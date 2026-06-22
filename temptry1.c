#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
int main()
{
    // shared memory
    int key = ftok("shmfile", 65);
    int shmid = shmget(key, 20, 0666 | IPC_CREAT);
    char *buf = (char *)shmat(shmid, NULL, 0);

    // pipe for parent and third process
    int fd[2];
    pipe(fd);
    // named semaphores for synchronization
    sem_t *semA = sem_open("/semA", O_CREAT, 0644, 1);
    sem_t *semB = sem_open("/semB", O_CREAT, 0644, 0);
    sem_t *semFull = sem_open("/semFull", O_CREAT, 0644, 0);

    //  Process A
    pid_t pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork failed");
        exit(-1);
    }
    if (pid1 == 0)
    {
        close(fd[0]); // close read end of pipe
        close(fd[1]); // close write end of pipe as process c will write on pipe
        int fd = open("Sensor1.txt", O_RDONLY);
        for (int i = 0; i < 10; i++)
        {
            sem_wait(semA);

            read(fd, &buf[i * 2], 1); // place in even index

            sem_post(semB);
        }
        close(fd);
        exit(0);
    }

    // Process B
    pid_t pid2 = fork();
    if (pid2 == -1)
    {
        perror("fork failed");
        exit(-1);
    }
    if (pid2 == 0)
    {
        close(fd[0]); // close read end of pipe
        close(fd[1]); // close write end of pipe as process c will write on pipe
        int fd = open("Sensor2.txt", O_RDONLY);
        for (int i = 0; i < 10; i++)
        {
            sem_wait(semB);

            read(fd, &buf[i * 2 + 1], 1); // place at odd index
            if (i == 9)                   // if last index that is 9*2+1=19 then move therefore signal to process c
                sem_post(semFull);

            sem_post(semA);
        }
        close(fd);
        exit(0);
    }

    //  Process C buff is fill so now write values on pipe and send to parent
    pid_t pid3 = fork();
    if (pid3 == -1)
    {
        perror("fork failed");
        exit(-1);
    }
    if (pid3 == 0)
    {
        sem_wait(semFull); // wait buffer full

        close(fd[0]); // close read end

        write(fd[1], buf, 20); // write on pipe from shared memory
        close(fd[1]);          // close write end
        exit(0);
    }

    //  Parent
    close(fd[1]); // close write end
    wait(NULL);
    wait(NULL);
    wait(NULL);
    char final[21];

    read(fd[0], final, 20);

    final[20] = '\0';
    printf("%s\n", final);
    close(fd[0]); // close read end

    shmctl(shmid, IPC_RMID, NULL);

    sem_unlink("/semA");
    sem_unlink("/semB");
    sem_unlink("/semFull");

    return 0;
}
