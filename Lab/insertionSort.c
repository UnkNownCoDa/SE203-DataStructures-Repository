#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size){
    printf("Array: [ ");
    for (int index = 0; index < size; ++index){
        printf("%d ", array[index]);
    }
    printf("]\n");
}

void insertionSort(int *array, int size){
    int value;
    for (int i= 0; i< size; ++i){
        for (int j = i; j < size; ++j){
            if (array[i] > array[j]){
                value = array[i];
                array[i] = array[j];
                array[j] = value;
            }
        }
    }
}

int main(void){
    int *array;  
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    array = (int*)malloc(sizeof(int)*size);
    for (int i = 0; i < size; ++i){
        printf("Enter element %d: ", i+1);
        scanf("%d", &array[i]);
    }
    printArray(array, size);
    insertionSort(array, size);
    printArray(array, size);

    free(array);
    return 0;
}