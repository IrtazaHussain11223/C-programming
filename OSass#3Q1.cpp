#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>
#include <cstdlib>
#include<sys/ipc.h>
#include<sys/shm.h>
using namespace std;
int main()
{
key_t key =ftok("shmfile",65);
int shmid= shmget(key,1024,0666|IPC_CREAT);
sem_t * str = (sem_t*) shmat(shmid,NULL,0);

int pipe1[2];
pipe(pipe1);

//sem_t * semoA= (sem_t *) shmat(shmid,NULL,0);
//sem_t * semoB= (sem_t *) shmat(shmid,NULL,0);
//sem_t * semoC= (sem_t *) shmat(shmid,NULL,0);
sem_t * semoA= &str[0];
sem_t * semoB= &str[1];
sem_t * semoC= &str[2];

sem_init(semoA,1,1);
sem_init(semoB,1,0);
sem_init(semoC,1,0);

char * buffer=(char*)(str+3);

int fd1= open("Sensor1.txt",O_RDONLY);
int fd2= open("Sensor2.txt",O_RDONLY); 

int *index = (int*)(buffer + 20);
*index=0;

pid_t p1=fork();
if(p1==0)
{
for(int i=0;i<10;i++)
{
sem_wait(semoA);
read(fd1,&buffer[*index],sizeof(char));
index[0]=index[0]+1;
//write(1,buffer[i],sizeof(int));
sem_post(semoB);
}
exit(0);
}
else
{
pid_t p2= fork();
if(p2==0)
{
for(int i=0;i<10;i++)
{
sem_wait(semoB);
read(fd2,&buffer[*index],sizeof(char));
//write(1,buffer[i],sizeof(int));
index[0]=index[0]+1;
if(index[0]>=20)
{
sem_post(semoC);
}
sem_post(semoA);
}
exit(0);
}
}
pid_t p3=fork();
if(p3==0)
{
sem_wait(semoC);
close(pipe1[0]);
write(pipe1[1],buffer,20);
close(pipe1[1]);
exit(0);
} 
wait(NULL);
wait(NULL);
wait(NULL);
char finalbuff[20];
read(pipe1[0],finalbuff,20);
for(int i=0;i<20;i++)
{
cout<<finalbuff[i]<<endl;
}
}

