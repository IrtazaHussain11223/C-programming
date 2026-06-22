#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void * worker()
{
printf("Thread ID: %lu , Process ID: %d\n", pthread_self(), getpid());
return NULL;
}

int main()
{
int N=5;
pthread_t threadID[N];
for(int i=0;i<N;i++)
{
pthread_create(&threadID[i],NULL,worker,NULL);

}
for(int i=0;i<N;i++)
{
pthread_join(threadID[i],NULL);

}
}
