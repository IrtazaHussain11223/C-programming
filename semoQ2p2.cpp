#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define BUFFER_SIZE 20
using namespace std;

int main() 
{
    key_t key = ftok(".", 'M');
    int shm_id = shmget(key, BUFFER_SIZE, 0666);
    char* shm_ptr = (char*) shmat(shm_id, NULL, 0);
    sem_t* sem_prod = sem_open("/sem_prod", 0);
    sem_t* sem_cons = sem_open("/sem_cons", 0);
    
    while(true)
     {
        sem_wait(sem_cons);
        
        if(shm_ptr[0] == '$') break;
        
        write(1, shm_ptr, BUFFER_SIZE);
        write(1, "\nPress Enter to continue...", 29);
        cin.get();
        
        sem_post(sem_prod);
    }
    
    
    shmdt(shm_ptr);  
    sem_close(sem_prod); sem_close(sem_cons);
    
    cout << "\nConsumer finished.\n";
    return 0;
}
