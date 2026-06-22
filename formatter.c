#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
struct header
{
    int timestamp;
    int datasize;
};
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("No file provided\n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    int mode = atoi(argv[2]);
    if(fd < 0)
    {
        perror("File open failed");
        return 1;
    }

    struct header h;
    read(fd, &h, sizeof(h));
    int data[10][10];
    read(fd, data, sizeof(data));
   if(mode == 1)
{
    printf("\n===== STATUS VIEW =====\n");
    printf("Timestamp: %d\n", h.timestamp);
    printf("Data Size: %d bytes\n", h.datasize);
}
else if(mode == 2)
{
    printf("\noriginal Matrix:\n");
for(int i=0;i<10;i++)
{
    for(int j=0;j<10;j++)
    {
        printf("%d ", data[i][j] - 5);
    }
    printf("\n");
}

printf("\nEncrypted Matrix:\n");
for(int i=0;i<10;i++)
{
    for(int j=0;j<10;j++)
    {
        printf("%d ", data[i][j]);
    }
    printf("\n");
}
}
else
{
    printf("invalid mode\n");
}

    close(fd);
    return 0;
}
