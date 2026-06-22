#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd = open("query_gate", O_WRONLY);
    if(fd < 0)
    {
        perror("FIFO open failed");
        return 1;
    }
    int choice;
    printf("===DASHBOARD ====\n");
    printf("1. Show Status\n");
    printf("2. Show Logs\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    write(fd, &choice, sizeof(choice));
    close(fd);
    return 0;
}
