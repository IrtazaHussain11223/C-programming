#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() 
{
    sem_t *mutex = sem_open("/mutex", O_CREAT, 0644, 1); 
    sem_t *s1 = sem_open("/s1", O_CREAT, 0644, 0);      
    sem_t *s2 = sem_open("/s2", O_CREAT, 0644, 0);      
    int fd = open("data.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
    const char* data = "10 20 30 40 50\n";
    write(fd, data, strlen(data));

    close(fd);
    pid_t p1 = fork();
    if (p1 == 0) 
    { 
        sem_wait(mutex);
        int fd = open("data.txt", O_RDWR);
        int num, sum = 0;
        char buffer[1024];
        ssize_t n = read(fd, buffer, sizeof(buffer)-1);
        if (n > 0) 
        {
            buffer[n] = '\0';
            char *ptr = strtok(buffer, " \n");
            while (ptr != nullptr)
             {
                sum += atoi(ptr);
                ptr = strtok(nullptr, " \n");
            }
        }
        lseek(fd, 0, SEEK_END);
        string sumStr = "Sum=" + to_string(sum) + "\n";
        write(fd, sumStr.c_str(), sumStr.size());
        close(fd);
        cout << "P1 done caldauted the sum)\n";
        sem_post(mutex);
        sem_post(s1); 
        sem_close(mutex); sem_close(s1); sem_close(s2);
        exit(0);
    }
    wait(NULL);
    pid_t p2 = fork();
    if (p2 == 0)
     { 
        sem_wait(s1); 
        sem_wait(mutex);

        int fd = open("data.txt", O_RDWR);
        int count = 0;
        char buffer[1024];
        ssize_t n = read(fd, buffer, sizeof(buffer)-1);
        if (n > 0) 
        {
            buffer[n] = '\0';
            char *ptr = strtok(buffer, " \n");
            while (ptr != nullptr) {
                if (isdigit(ptr[0])) count++;
                ptr = strtok(nullptr, " \n");
            }
        }

        lseek(fd, 0, SEEK_END);
        string countstr = "Count=" + to_string(count) + "\n";
        write(fd, countstr.c_str(), countstr.size());
        close(fd);
        cout << "p2 calculated the count\n";
        sem_post(mutex);
        sem_post(s2);
        sem_close(mutex); sem_close(s1); sem_close(s2);
        exit(0);
    }
    wait(NULL);
    pid_t p3 = fork();
    if (p3 == 0)
     { 
        sem_wait(s2); 
        sem_wait(mutex);
        int fd = open("data.txt", O_RDONLY);
        char buffer[1024];
        ssize_t n = read(fd, buffer, sizeof(buffer)-1);
        buffer[n] = '\0';
        close(fd);
        int sum = 0, count = 0;
        char *ptr = strtok(buffer, " \n");
        while (ptr != nullptr) {
            if (strncmp(ptr, "Sum=", 4) == 0) sum = atoi(ptr + 4);
            if (strncmp(ptr, "Count=", 6) == 0) count = atoi(ptr + 6);
            ptr = strtok(nullptr, " \n");
        }

        float avg = (float)sum / count;
        cout << "P3: Average = " << avg << endl;

        sem_post(mutex);
        sem_close(mutex); sem_close(s1); sem_close(s2);
        exit(0);
    }
    wait(NULL);
    sem_close(mutex); sem_close(s1); sem_close(s2);
    sem_unlink("/mutex"); sem_unlink("/s1"); sem_unlink("/s2");

    return 0;
}
