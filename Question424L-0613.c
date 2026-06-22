#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
int pipe1[2],pipe2[2];
pipe(pipe1);
pipe(pipe2);
pid_t pid=fork();
if(pid==0){
close(pipe1[1]);
close(pipe2[0]);
char doc[200],cleaned[200];
read(pipe1[0],doc,sizeof(doc));
int j=0;
for(int i=0;i<strlen(doc);i++){
if(isalpha(doc[i])||isspace(doc[i])){
cleaned[j]=doc[i];
j++;
}}
cleaned[j]='\0';
write(pipe2[1],cleaned,strlen(cleaned)+1);
close(pipe1[0]);
close(pipe2[1]);
exit(0);
}
else{
close(pipe1[0]);
close(pipe2[1]);
char doc[200];
printf("Teacher: Enter document:\n");
fgets(doc,sizeof(doc),stdin);
write(pipe1[1],doc,strlen(doc)+1);
close(pipe1[1]);
char cleaned[200];
read(pipe2[0],cleaned,sizeof(cleaned));
printf("Cleaned document:\n%s\n",cleaned);
close(pipe2[0]);
}
return 0;
}
