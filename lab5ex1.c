#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int var=0;
void *worker(void * param)
{
var=*(int *)param;
pthread_exit(0);
}
int main()
{
printf("BEfire thread execution var=%d",var);
int value =10;
pthread_t threadID;
pthread_create(&threadID,NULL,worker,&value);
pthread_join(threadID,NULL);
printf("After thread exec var = %d",var);
return 0;
}

