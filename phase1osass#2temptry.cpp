#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<cstdlib>
#include<ctime>
#include<sys/types.h>
#include<pthread.h>
#include <fcntl.h> 
#include <sys/stat.h>

using namespace std;

int matrix[10][10];

struct block
{
    int sr, er, sc, ec;
};

void * worker(void * param)
{
    block *b = (block*)param;

    for(int i=b->sr; i<=b->er; i++)
    {
        for(int j=b->sc; j<=b->ec; j++)
        {
            if(matrix[i][j] > 90)
            {
                int sum=0, count=0;

                if(i-1>=0){ sum+=matrix[i-1][j]; count++; }
                if(i+1<=9){ sum+=matrix[i+1][j]; count++; }
                if(j-1>=0){ sum+=matrix[i][j-1]; count++; }
                if(j+1<=9){ sum+=matrix[i][j+1]; count++; }

                matrix[i][j] = sum / count;
            }
        }
    }
    return NULL;
}

int main()
{
    int c1_p[2], c2_p[2];
    pipe(c1_p);
    pipe(c2_p);

    pid_t pid1 = fork();

    if(pid1 == 0)
    {
        int g1[2], g2[2];
        pipe(g1);
        pipe(g2);

        if(fork() == 0)
        {
            srand(time(0)+getpid());
            close(g2[0]);
            for(int i=0;i<50;i++)
            {
                int n = rand()%101;
                write(g2[1], &n, sizeof(n));
            }
            close(g2[1]);
            exit(0);
        }

        if(fork() == 0)
        {
            srand(time(0)+getpid());
            close(g1[0]);
            for(int i=0;i<50;i++)
            {
                int n = rand()%101;
                write(g1[1], &n, sizeof(n));
            }
            close(g1[1]);
            exit(0);
        }

        close(g1[1]); close(g2[1]); close(c1_p[0]);

        for(int i=0;i<50;i++)
        {
            int n1,n2;
            read(g1[0], &n1, sizeof(n1));
            read(g2[0], &n2, sizeof(n2));
            int avg = (n1+n2)/2;
            write(c1_p[1], &avg, sizeof(avg));
        }

        close(g1[0]); close(g2[0]); close(c1_p[1]);
        wait(NULL); wait(NULL);
        exit(0);
    }

    if(fork() == 0)
    {
        int g1[2], g2[2];
        pipe(g1);
        pipe(g2);

        if(fork() == 0)
        {
            srand(time(0)+getpid());
            close(g2[0]);
            for(int i=0;i<50;i++)
            {
                int n = rand()%101;
                write(g2[1], &n, sizeof(n));
            }
            close(g2[1]);
            exit(0);
        }

        if(fork() == 0)
        {
            srand(time(0)+getpid());
            close(g1[0]);
            for(int i=0;i<50;i++)
            {
                int n = rand()%101;
                write(g1[1], &n, sizeof(n));
            }
            close(g1[1]);
            exit(0);
        }

        close(g1[1]); close(g2[1]); close(c2_p[0]);

        for(int i=0;i<50;i++)
        {
            int n1,n2;
            read(g1[0], &n1, sizeof(n1));
            read(g2[0], &n2, sizeof(n2));
            int avg = (n1+n2)/2;
            write(c2_p[1], &avg, sizeof(avg));
        }

        close(g1[0]); close(g2[0]); close(c2_p[1]);
        wait(NULL); wait(NULL);
        exit(0);
    }

    close(c1_p[1]); close(c2_p[1]);

    int i=0,j=0,count=0;

    while(count < 100)
    {
        int a,b;
        read(c1_p[0], &a, sizeof(a));
        read(c2_p[0], &b, sizeof(b));

        matrix[i][j]=a; j++; count++;
        if(j==10){ j=0; i++; }

        if(count>=100) break;

        matrix[i][j]=b; j++; count++;
        if(j==10){ j=0; i++; }
    }

    pthread_t t1,t2,t3,t4;
    block bdata[4];

    int idx=0;
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<2;c++)
        {
            bdata[idx].sr = r*5;
            bdata[idx].er = r*5+4;
            bdata[idx].sc = c*5;
            bdata[idx].ec = c*5+4;
            idx++;
        }
    }

    pthread_create(&t1,NULL,worker,&bdata[0]);
    pthread_create(&t2,NULL,worker,&bdata[1]);
    pthread_create(&t3,NULL,worker,&bdata[2]);
    pthread_create(&t4,NULL,worker,&bdata[3]);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);

    int p1[2], p2[2];
    pipe(p1); pipe(p2);

    if(fork()==0)
    {
        int data[10][10];
        read(p1[0], data, sizeof(data));

        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                data[i][j]+=5;

        write(p2[1], data, sizeof(data));
        exit(0);
    }

    if(fork()==0)
    {
        int data[10][10];
        read(p2[0], data, sizeof(data));

        struct header { int t,s; } h;
        h.t = time(0);
        h.s = sizeof(data);

        int fd = open("vaultDB", O_WRONLY|O_CREAT|O_TRUNC, 0644);
        write(fd,&h,sizeof(h));
        write(fd,data,sizeof(data));
        close(fd);
        exit(0);
    }

    write(p1[1], matrix, sizeof(matrix));
    close(p1[1]); close(p2[1]);
    wait(NULL); wait(NULL);

    if(mkfifo("query_gate",0666)==-1){}

    while(true)
    {
        cout<<"\nWaiting for dashboard...\n";
        int fd = open("query_gate", O_RDONLY);

        int req;
        read(fd,&req,sizeof(req));
        close(fd);

        if(req==1)
        {
            if(fork()==0)
                execl("./formatter","formatter","vaultDB","1",NULL);
            wait(NULL);
        }
        else if(req==2)
        {
            if(fork()==0)
                execl("./formatter","formatter","vaultDB","2",NULL);
            wait(NULL);
        }
        else
            cout<<"Invalid request\n";
    }

    return 0;
}
