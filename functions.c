#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void sort(int array[], int n, bool order) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (order == true) 
            {
                if (array[i] > array[j]) 
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            } 
            else
             {
                if (array[i] < array[j]) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
}

int findHighest(int array[], int size)
 {
    int m = array[0];
    for (int i = 1; i < size; i++)
     {
        if (array[i] > m) {
            m = array[i];
        }
    }
    return m;
}




void print(int array[], int size) 
{ 
for (int i = 0; i < size; i++)
 { 
 printf("%d ", array[i]);
 }
   printf("\n"); 
   }
