#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include <stdlib.h>
int main()
{
key_t key = ftok("shmfile", 65);
int shmid= shmget(key,1024,0666);
char * str = (char *) shmat(shmid, NULL, 0);
printf("Daat from shaed memeory is %s\n",str);
int sum=0;
int count=0;
char * token = strtok(str," ");
while(token!=NULL)

{
int num = atoi(token);
    sum += num;
    count++;
    token = strtok(NULL, " ");
}

float avg = (float)sum/count;
printf("Sum = %d\n", sum);
printf("Average = %f\n", avg);
shmdt(str);
shmctl(shmid, IPC_RMID, NULL);
}
