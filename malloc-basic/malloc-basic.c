#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;
    int *arr;

    printf("How many numbers do you want to print?\n");
    scanf("%d", &size);

    arr = (int *) malloc(size * sizeof(int));

    for(int i = 0; i < size; i++) {
        printf("Number no. %d\n", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", i + 1, arr[i]);
    }
    

    return 0;
}