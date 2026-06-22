#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void *worker(void * params)
{
int *num=(int *)params;
num[0]+=10;
num[1]+=10;
printf("New thread   value[0] -%d abd value[1] %d",num[0],num[1]);
pthread_exit(num);
}
int main()
{
int values[]={10,20};
pthread_t threadID;
pthread_create(&threadID,NULL,worker,(void *) values);
int *upd_val;
pthread_join(threadID,(void **)&upd_val);
printf("main thread is value[0] %d  and value[1] %d",upd_val[0],upd_val[1]);
return 0;
}

