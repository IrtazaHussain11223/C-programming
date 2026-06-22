#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
# define size 50
int main()
{
int fd[2];
pipe(fd);
pid_t v1=fork();
const char* mess="hellow from parent";
if(v1!=0)
{
int wsize = write( fd[1],mess,strlen(mess));
close(fd[0]);
}
else
{
char buff[size];
memset(buff,'\0',size);
int isize=read(fd[0],buff,size);
write(1,buff,isize);
}
