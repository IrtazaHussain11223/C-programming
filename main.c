#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

int main(int argc, char *argv[]) {
    int arr[100];
    int n;
    int order;
    int i;
    int highest;
    order = atoi(argv[argc - 1]);
    n = argc - 2;

    for (i = 0; i < n; i++) 
    {
        arr[i] = atoi(argv[i + 1]);
    }
    print(arr, n);
    sort(arr, n, order);
    print(arr, n);
    highest = findHighest(arr, n);
    printf("Highest = %d\n", highest);
    return 0;
}
