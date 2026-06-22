#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<cstdlib>
#include<ctime>
#include<sys/types.h>
#include<pthread.h>
#include <fcntl.h> 
#include <sys/stat.h>
int matrix[10][10];
int sr[4] = {0, 0, 5, 5};   // start rows
int er[4] = {4, 4, 9, 9};   // end rows
int sc[4] = {0, 5, 0, 5};   // start cols
int ec[4] = {4, 9, 4, 9};   // end cols
using namespace std;
void * worker(void * param)
{

int n= *(int *)param;
for(int i=sr[n];i<=er[n];i++)
 {
   for(int j=sc[n];j<=ec[n];j++)
    {
     if(matrix[i][j]>90)
      {
       int sum=0;
       int count=0;
       if(i-1>=0)// upward
        { 
         sum+=matrix[i-1][j];
         count++;
        }
        
        if(i+1<=9)// downward
        { 
         sum+=matrix[i+1][j];
         count++;
        }
        
        if(j-1>=0)// upward
        { 
         sum+=matrix[i][j-1];
         count++;
        }
        
        if(j+1<=9)// upward
        { 
         sum+=matrix[i][j+1];
         count++;
        }
        matrix[i][j]=sum/count;
      }
    }
 }
 return NULL;
}

int main()
{
    int c1_p[2];
    int c2_p[2];
    pipe(c1_p);
    pipe(c2_p);
    if(pipe(c1_p) == -1)
{
    perror("pipe  c1 p failed");
    exit(1);
}
if(pipe(c2_p) == -1)
{
    perror("pipe c2 p failed");
    exit(1);
}

    pid_t pid1 = fork();
    if(pid1 < 0)
{
    perror("fork failed");
    exit(1);
}

    if(pid1 == 0)
    {
        int c1_g1[2], c1_g2[2];
        pipe(c1_g1);
        pipe(c1_g2);
        if(pipe(c1_g1) == -1)
{
    perror("pipe c g1 failed");
    exit(1);
}
if(pipe(c1_g2) == -1)
{
    perror("pipe c1 g1 failed");
    exit(1);
}
        pid_t pid2 = fork();
        if(pid2 < 0)
{
    perror("fork failed");
    exit(1);
}

        if(pid2 == 0)
        {
            srand(time(0) + getpid());
            close(c1_g2[0]);
            for(int i = 0; i < 50; i++)
            {
                int n = rand() % 101;
                write(c1_g2[1], &n, sizeof(n));
                sleep(0);
            }
            close(c1_g2[1]);
            exit(0);
        }
        else
        {
            pid_t pid3 = fork();
            if(pid3 < 0)
{
    perror("fork failed");
    exit(1);
}

            if(pid3 == 0)
            {
                srand(time(0) + getpid());
                close(c1_g1[0]);
                for(int i = 0; i < 50; i++)
                {
                    int n = rand() % 101;
                    write(c1_g1[1], &n, sizeof(n));
                    sleep(0);
                }
                exit(0);
            }
            else
            {
                close(c1_g1[1]);
                close(c1_g2[1]);
                close(c1_p[0]);
                for(int i = 0; i < 50; i++)
                {
                    int n1;
                    read(c1_g1[0], &n1, sizeof(n1));
                    int n2;
                    read(c1_g2[0], &n2, sizeof(n2));
                    int avg = (n1 + n2) / 2;
                    write(c1_p[1], &avg, sizeof(avg));
                }
                    close(c1_g1[0]);
                    close(c1_g2[0]);
                    close(c1_p[1]);
                    wait(NULL);
                    wait(NULL);
                    exit(0);
            }
        }
    }
    else
    {
        pid_t pid4 = fork();
        if(pid4 < 0)
{
    perror("fork failed");
    exit(1);
}
        if(pid4 == 0)
        {
            int c2_g2[2], c2_g1[2];
            pipe(c2_g1);
            pipe(c2_g2);
            if(pipe(c2_g1) == -1)
{
    perror("pipe c2 g1 failed");
    exit(1);
}
if(pipe(c2_g2) == -1)
{
    perror("pipe c2 g1 failed");
    exit(1);
}
            pid_t pid5 = fork();
if(pid5 < 0)
{
    perror("fork failed");
    exit(1);
}
            if(pid5 == 0)
            {
                srand(time(0) + getpid());
                close(c2_g2[0]);
                for(int i = 0; i < 50; i++)
                {
                    int n = rand() % 101;
                    write(c2_g2[1], &n, sizeof(n));
                    sleep(0);
                }
                 close(c2_g2[1]);
                 exit(0);
            }
            else
            {
                pid_t pid6 = fork();
                if(pid6 < 0)
{
    perror("fork failed");
    exit(1);
}

                if(pid6 == 0)
                {
                    srand(time(0) + getpid());
                    close(c2_g1[0]);
                    for(int i = 0; i < 50; i++) 
                    {
                        int n = rand() % 101;
                        write(c2_g1[1], &n, sizeof(n));
                        sleep(0);
                    }
                     close(c2_g1[1]);
                     exit(0);
                }
                else
                {
                    close(c2_g1[1]);
                    close(c2_g2[1]);
                    close(c2_p[0]);
                    for(int i = 0; i < 50; i++)
                    {
                        int n1;
                        read(c2_g1[0], &n1, sizeof(n1));
                        int n2;
                        read(c2_g2[0], &n2, sizeof(n2));
                        int avg = (n1 + n2) / 2;
                        write(c2_p[1], &avg, sizeof(avg));
                    }
                    close(c2_g1[0]);
                    close(c2_g2[0]);
                    close(c2_p[1]);
                    wait(NULL);
                    wait(NULL);
                    exit(0);
                }
            }
        }
        else
        {
            close(c1_p[1]);
            close(c2_p[1]);
            int i=0,j=0;
            //int matrix[10][10];
            int count=0;
            while(count<100)
            {
                int avg1, avg2;
                read(c1_p[0], &avg1, sizeof(avg1));
                read(c2_p[0], &avg2, sizeof(avg2));
                //cout << "Parent received: " << avg1 << " , " << avg2 << endl;
                //cout<<"The avergae will be "<<avg_p<<endl;
                while(true) // to store first average
                {
                matrix[i][j]=avg1;
                j++;
                count++;
                if(j==10)
                 {
                 j=0;
                 i++;
                 }
                 if(i>=10)
                 break;
                 break;
                }
                
                while(true) // to store 2nd average
                {
                matrix[i][j]=avg2;
                j++;
                count++;
                if(j==10)
                 {
                 j=0;
                 i++;
                 }
                 if(i>=10)
                 break;
                 break;
                }
               
                if(count>=100) // when count reaches 100
                 {
                  pthread_t t1,t2,t3,t4;
                  int id[4]={0,1,2,3};
                  pthread_create(&t1,NULL,worker,&id[0]);
                  pthread_create(&t2,NULL,worker,&id[1]);
                  pthread_create(&t3,NULL,worker,&id[2]);
                  pthread_create(&t4,NULL,worker,&id[3]);
                  
                  pthread_join(t1, NULL);
                  pthread_join(t2, NULL);
                  pthread_join(t3, NULL);
                  pthread_join(t4, NULL);
                  i=0;
                  j=0;count=0;// reset
                  break;  // Exit the while loop
                 } 
             }
        }//phase 3    
        int p1[2];//parent to b
        int p2[2]; // b tp c process
        pipe(p1);
        pipe(p2);
        if(pipe(p1) == -1)
{
    perror("pipe  p1  failed");
    exit(1);
}
if(pipe(p2) == -1)
{
    perror("pipe p2 failed");
    exit(1);
}
       pid_t pidB=fork();
       if(pidB==0)
       {
       int data[10][10];
       read(p1[0],data,sizeof(data));//read form the pipe
       for(int i=0;i<10;i++)// encryption
       {
         for(int j=0;j<10;j++)
          {
           data[i][j]= data[i][j]+5;
          }       
       }

       write(p2[1],data,sizeof(data));
       close(p1[0]);
       close(p2[1]);
       exit(0);
       }
       pid_t pidC=fork();
       if(pidC==0)
       {
       close(p2[1]);
       int ndata[10][10];
       read(p2[0],ndata,sizeof(ndata));
        struct header
        {
        int timestamp;
        int datasize;
        };
       
       header h;
       h.timestamp = time(0);
       h.datasize=sizeof(matrix);
       int fd = open("vaultDB", O_WRONLY | O_CREAT | O_TRUNC, 0644);
       if(fd<0)
         {
          perror("File open failed");
          exit(1);
         }
         write(fd,&h,sizeof(h));
         write(fd, ndata, sizeof(ndata));
         close(fd); 
         close(p2[0]);
         exit(0);
       }
     
       {// parent 
       close(p1[0]);
       write(p1[1],matrix,sizeof(matrix));
       close(p1[1]);
       close(p2[0]);
       close(p2[1]);
       wait(NULL);
       wait(NULL);
      }
        
    }

//phase 4
 mkfifo("query_gate", 0666);
 while(true)
{
    cout << "\nmain waiting for dashboard request\n";
    int fd = open("query_gate", O_RDONLY);
    if(fd < 0)
    {
        perror("FIFO open failed");
        continue;
    }
    int req;
    read(fd, &req, sizeof(req));
    close(fd);
    cout << "[main received request: " << req << endl;
    if(req == 1)
{
    pid_t p = fork();
    if(p < 0)
{
    perror("fork failed");
    exit(1);
}
    if(p == 0)
    {
        execl("./formatter", "formatter", "vaultDB", "1", NULL);
        perror("exec failed");
        exit(1);
    }
    wait(NULL);
}
else if(req == 2)
{
    pid_t p = fork();
    if(p < 0)
{
    perror("fork failed");
    exit(1);
}
    if(p == 0)
    {
        execl("./formatter", "formatter", "vaultDB", "2", NULL);
        perror("exec failed");
        exit(1);
    }
    wait(NULL);
}
else
{
    cout << "Invalid request\n";
}
}
    return 0;
}
