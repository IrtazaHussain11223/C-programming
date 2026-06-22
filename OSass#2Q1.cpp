#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>
using namespace std;
int main()
{
int buffer1[10];
int buffer2[10];
pid_t p1=fork();
if(p1==0)
 {
  int fd1= open("Sensor1.txt",O_RDONLY);
  read(fd1,buffer1,10);
  write(1,buffer1,10);
  exit(0);
 }
 
pid_t p2= fork();
if(p2==0)
 {
 int fd2= open("Sensor2.txt",O_RDONLY); 
 read(fd2,buffer2,10);
 write(1,buffer2,10);
 }
 wait(NULL);
 wait(NULL);
}
