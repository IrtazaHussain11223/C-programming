#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void * worker(void * num)
{
int n=(int)num;
int sum=0;
for(int i=0;i<=n;i++)
{
sum=sum+i;
}
printf("The sum is %d",sum);
return NULL;
}
int main()
{
int n=5;
pthread_t threadID;
pthread_create(&threadID,NULL,worker,(void *)n);
pthread_join(threadID, NULL);

}
