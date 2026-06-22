#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
int fd;
char msg[]="Hello from writer";
fd=open("mypipe",O_WRONLY);
write(fd,msg,strlen(msg)+1);
close(fd);
return 0;
}
