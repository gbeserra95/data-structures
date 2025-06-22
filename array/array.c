#include <stdio.h>
#include <stdlib.h>

#include "../helpers.h"

int main(void)
{
    int n = 8;
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        arr[i] = i;

    n++;
    
    int *new_arr = malloc(n * sizeof(int));

    arrcpy(n, arr, new_arr);
    free(arr);

    arr = new_arr;
    arr[n - 1] = 12;

    print_arr(n, arr);
    free(arr);
}