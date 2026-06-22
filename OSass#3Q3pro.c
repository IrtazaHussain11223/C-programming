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
#include <sys/stat.h>
#include <time.h>
int main()
{
mkfifo("myfifo", 0666);
sem_t *empty = sem_open("/mysemo1",O_CREAT,0644,1);
sem_t *full  = sem_open("/mysemo2",O_CREAT,0644,0);
int fd = open("myfifo", O_WRONLY);
srand(time(NULL));

for(int i=0;i<50;i++)
 {
  int r= rand()%100;
  sem_wait(empty);             
  write(fd, &r, sizeof(int));
  printf("produced %d\n", r);
  sem_post(full);
  //sleep(0);
 }
 close(fd);
 sem_close(empty);
 sem_close(full);
 
 sem_unlink("/mysemo1");
 sem_unlink("/mysemo2");
}
