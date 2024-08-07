#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size){
    printf("Array: [ ");
    for (int index = 0; index < size; ++index){
        printf("%d ", array[index]);
    }
    printf("]\n");
}

void selectionSort(int *array, int size){
    int min_index, value;
    for (int i = 0; i < size;++i){
        min_index = i;
        for (int j = i; j < size; ++j){
            if (array[min_index] > array[j]){
                min_index = j;
            }
        }
        value = array[min_index];
        array[min_index] = array[i];
        array[i] = value;

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
    selectionSort(array, size);
    printArray(array, size);

    free(array);
    return 0;
}