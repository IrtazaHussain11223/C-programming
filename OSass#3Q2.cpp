#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>
#include <cstdlib>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<pthread.h>
#include<string.h>
using namespace std;
int N=10;
int potentialPatients = N;
int coronaPatient=0;
sem_t booth;
sem_t mutax;
void * worker(void * arg)
{
string result;
sem_wait(&booth);
int r = rand()%2+1;
if(r==2)
{
cout<<"infencted\n";
result="infected";
sem_wait(&mutax);
coronaPatient++;
sem_post(&mutax);
}
else
{
cout<<"Not infected\n";
result="not infected";
}

sem_wait(&mutax);
int fd= open("semolog.txt",O_WRONLY|O_APPEND|O_CREAT ,0666);
if(fd < 0)
{
perror("open failed");
pthread_exit(0);
}
pthread_t id = pthread_self();
string data = to_string((unsigned long)id) + "\n";
write(fd,data.c_str(),data.length());
write(fd,result.c_str(),result.length());
potentialPatients--;
close(fd);
sem_post(&mutax);
sem_post(&booth);
pthread_exit(0);

}
int main()
{
pthread_t T[N];
//key_t key = ftok("shmfile",65);
//int shmid= shmget(key,1024,0666|IPC_CREAT);

sem_init(&booth,0,3);
sem_init(&mutax,0,1);
srand(time(0));
for(int i=0;i<N;i++)
 {
 pthread_create(&T[i],NULL,worker,NULL);
 }
 for(int i=0;i<N;i++)
 {
 pthread_join(T[i],NULL);
 }
}
