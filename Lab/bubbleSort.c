#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size){
    printf("Array: [ ");
    for (int index = 0; index < size; ++index){
        printf("%d ", array[index]);
    }
    printf("]\n");
}

void bubbleSort(int *array, int size){
    int value;
    for (int i= 0; i< size; ++i){
        for (int j = 0; j < size - 1; ++j){
            if (array[j] > array[j+1]){
                value = array[j];
                array[j] = array[j+1];
                array[j+1] = value;
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
    bubbleSort(array, size);
    printArray(array, size);

    free(array);
    return 0;
}