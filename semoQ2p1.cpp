#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#define BUFFER_SIZE 20
using namespace std;

int main(int argc, char* argv[])
 {
    int src_fd = open(argv[1], O_RDONLY);
    key_t key = ftok(".", 'M');
    int shm_id = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666);
    char* shm_ptr = (char*) shmat(shm_id, NULL, 0); 
    sem_t* sem_prod = sem_open("/sem_prod", O_CREAT, 0666, 1);
    sem_t* sem_cons = sem_open("/sem_cons", O_CREAT, 0666, 0);
    char buffer[BUFFER_SIZE];
    ssize_t n;
    while((n = read(src_fd, buffer, BUFFER_SIZE)) > 0) 
    {
        sem_wait(sem_prod);
        memset(shm_ptr, 0, BUFFER_SIZE);
        memcpy(shm_ptr, buffer, n);
        sem_post(sem_cons);
    }
    sem_wait(sem_prod);
    shm_ptr[0] = '$';
    sem_post(sem_cons);
    shmdt(shm_ptr); 
    close(src_fd);
    sem_close(sem_prod); sem_close(sem_cons);
    sem_unlink("/sem_prod"); sem_unlink("/sem_cons");
    shmctl(shm_id, IPC_RMID, NULL);
    cout << "producer finished.\n";
    return 0;
}
