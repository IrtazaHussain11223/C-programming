#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main() 
{
    sem_t *sem = sem_open("/my_sem", O_CREAT, 0644, 0);
    pid_t pid = fork();
    
    if (pid == 0)
     {
        sem_wait(sem);
        printf("child proceedings\n");
        sem_close(sem);
        exit(0);
    }
    else {
        printf("parent: ready\n");
        fflush(stdout);
        sem_post(sem);
        wait(NULL);
        sem_close(sem);
        sem_unlink("/my_sem");
    }
    
    return 0;
}
