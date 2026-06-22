#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
int main()
{
sem_t *semog1= sem_open("/mysem1",O_CREAT,0644,1);
sem_t *semoc1=sem_open("/mysem2",O_CREAT,0644,0);
sem_t *semop1=sem_open("/mysem3",O_CREAT,0644,0);
pid_t pid1=fork();
if(pid1==0)
{

pid_t pid2=fork();
 {
 if(pid2==0)
  {
  sem_wait(semog1);
  char *s = "INIT\n";
  int fd = open("grandfile.txt",O_WRONLY|O_CREAT|O_APPEND,0666);
  write(fd,s,strlen(s));
  close(fd);
  sem_post(semoc1);
  exit(0);
  }
  else
  {
   sem_wait(semoc1);
   char *s = "PROCESSED";
   int fd = open("grandfile.txt",O_WRONLY|O_APPEND,0666);
   write(fd,s,strlen(s));
   close(fd);
   sem_post(semop1);
   exit(0);
  
  }
 }
 }
 else
 {
 sem_wait(semop1);
 char buf[100];
 int fd = open("grandfile.txt",O_RDONLY,0666);
 int n = read(fd, buf, sizeof(buf));
 write(1,buf,n);
 close(fd);
 sem_post(semop1);
}
sem_close(semog1);
sem_close(semoc1);
sem_close(semop1);

sem_unlink("/mysem1");
sem_unlink("/mysem2");
sem_unlink("/mysem3");

}
