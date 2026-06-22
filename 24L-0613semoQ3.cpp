#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <sys/wait.h>
using namespace std;
void readFile(const char* filename, int &sum, int &count) 
{
    ifstream file(filename);
    int x;
    sum = 0;
    count = 0;
while (file >> x) 
{
        sum += x;
        count++;
}
}

int main() 
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 6 * sizeof(int), 0666 | IPC_CREAT);
    int *shm = (int*) shmat(shmid, NULL, 0);
    int semid = shmget(key+1, 4 * sizeof(sem_t), 0666 | IPC_CREAT);
    sem_t *sem = (sem_t*) shmat(semid, NULL, 0);
    shm[4] = 0; 
    sem_init(&sem[0], 1, 1); // mutex
    sem_init(&sem[1], 1, 2); // empty
    sem_init(&sem[2], 1, 0); // full
    sem_init(&sem[3], 1, 0); // done
    for (int p = 0; p < 2; p++)
 {
        if (fork() == 0)
         {
            int sum, count;

            if (p == 0)
                readFile("Filetry1.txt", sum, count);
            else
                readFile("file2.txt", sum, count);
            sem_wait(&sem[1]); 
            sem_wait(&sem[0]); 
            int i = shm[4];
            shm[i] = sum;          
            shm[i + 2] = count;   
            shm[4]++;
            sem_post(&sem[0]);
            sem_post(&sem[2]); 
            sem_wait(&sem[3]); 
            cout << "Process "<< p+1<<" Sum = " << sum<< " Average = "<< shm[5]<<endl;

            _exit(0);
    }
    }
    sem_wait(&sem[2]);
    sem_wait(&sem[2]);
    float total_sum = shm[0] + shm[1];
    int total_count = shm[2] + shm[3];
    shm[5] = total_sum / total_count; 
    cout << "Server Average = " << shm[5] << endl;
    sem_post(&sem[3]);
    sem_post(&sem[3]);
    wait(NULL);
    wait(NULL);
    sem_destroy(&sem[0]);
    sem_destroy(&sem[1]);
    sem_destroy(&sem[2]);
    sem_destroy(&sem[3]);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    shmdt(sem);
    shmctl(semid, IPC_RMID, NULL);
}
