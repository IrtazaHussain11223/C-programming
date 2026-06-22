#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <fcntl.h>
#include <unistd.h> 
#include<string.h>
int main(int argc, char * argv[])
{
char buffer[256];

if(argc<2)
 {
  printf("Not valid file\n");
  return 1; 
 }
 
 int fd = open(argv[1],O_RDONLY);
 char buff[100];
 int n = read(fd,buffer,sizeof(buffer)-1);
 if(n<0)
 {
 printf("Error readinf  filee\n");
 return 1;
 }
 buffer[n]='\0';
 close(fd);
 
 key_t key = ftok("shmfile",65);
 int shmid = shmget(key,1024, 0666| IPC_CREAT);
 char * str = (char *) shmat(shmid,NULL,0);
 strcpy(str,buffer);
printf("shared mmeory data is %s\n ",str);
 shmdt(str);
}
