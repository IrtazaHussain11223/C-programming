#include <stdio.h>      
#include <stdlib.h>    
#include <string.h>     
#include <sys/ipc.h>    
#include <sys/shm.h>    
#include <unistd.h>   
#include<iostream>
using namespace std;
struct shared_data
{
int flag;
char message[100];
};

int main()
{
key_t key = ftok("shmfile",65);
int shmid = shmget(key,1024,0666|IPC_CREAT);
shared_data* str = (shared_data*) shmat(shmid, NULL , 0);
while(true)
 {
  while(str->flag==1)
   usleep(1000);
   strcpy(str->message,"Message from Producer");
   str->flag=1;
   cout<<"Producre wrote: "<<str->message<<endl;
   sleep(1);
 }
shmdt(str);
return 0;
}
