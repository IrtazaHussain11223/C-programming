#include <stdio.h>      
#include <stdlib.h>    
#include <string.h>     
#include <sys/ipc.h>    
#include <sys/shm.h>    
#include <unistd.h>   
#include <iostream>
using namespace std;

struct shared_data
{
    int flag;
    char message[100];
};

int main()
{
key_t key = ftok("shmfile",65);
int shmid = shmget(key,sizeof(shared_data),0666);
shared_data* str= (shared_data*) shmat(shmid,NULL,0);
while(true)
 {
 while(str->flag==0)
 usleep(1000);
 cout<<"MEssage comsuner got is "<<str->message<<endl;
 str->flag=0;
 sleep(1);
 }
shmdt(str);
shmctl(shmid, IPC_RMID, NULL);
return 0;
}
