#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>

int total = 0;
int fd;

sem_t *full;
sem_t *empty;
sem_t mutex;

void* worker(void *arg)
{
 int num;

for(int i = 0; i < 25; i++)
 {
sem_wait(full);
sem_wait(&mutex);
read(fd, &num, sizeof(int));
total += num;
printf("Thread %ld added %d total %d\n",
(long)pthread_self(), num, total);
sem_post(&mutex);
sem_post(empty);
}
return NULL;
}

int main()
{
fd = open("myfifo", O_RDONLY);
full = sem_open("/mysemo2", 0);
empty = sem_open("/mysemo1", 0);
 sem_init(&mutex, 0, 1);
 pthread_t t1, t2;
pthread_create(&t1, NULL, worker, NULL);
pthread_create(&t2, NULL, worker, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
 printf("FINAL TOTAL %d\n", total);
 close(fd);

sem_close(full);
sem_close(empty);
sem_destroy(&mutex);

    return 0;
}
