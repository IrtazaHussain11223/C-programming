#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int fib[MAX];
void * worker(void *arg)
{

int N = *(int *)arg; // get N from argument
fib[0] = 0;
 if(N > 1) fib[1] = 1;
 printf("Fibonacci series (thread ID: %lu): ", pthread_self());
for(int i = 0; i < N; i++)
 {
 if(i > 1)
fib[i] = fib[i-1] + fib[i-2];
printf("%d ", fib[i]);
}
printf("\n");
    return NULL;
}

void *even(void * n)
{
int N = *(int *)n;
int c=0;
for(int i=0;i<N;i++)
{
if(fib[i]%2==0)
c++;
}
printf("even numbers are%d",c);
return NULL;
}

void *odd(void * n)
{
int N = *(int *)n;
int c=0;
for(int i=0;i<N;i++)
{
if(fib[i]%2==1)
c++;
}
printf("odd numbers are%d",c);
return NULL;
}

void *sum(void * n)
{
int N = *(int *)n;
int c=0;
for(int i=0;i<N;i++)
{
c+=fib[i];
}
printf("sum is are%d",c);
return NULL;
}



int main(int argc, char *argv[])
{
int num = atoi(argv[1]);
pthread_t threadID1;
pthread_create(&threadID1,NULL,worker,(void *)&num);
pthread_join(threadID1,NULL);

pthread_t threadID2;
pthread_create(&threadID2,NULL,even,(void *)&num);
pthread_join(threadID2,NULL);

pthread_t  threadID3;
pthread_create(&threadID3,NULL,odd,(void *)&num);
pthread_join(threadID3,NULL);


pthread_t  threadID4;
pthread_create(&threadID4,NULL,sum,(void *)&num);
pthread_join(threadID4,NULL);
return 0;

}
