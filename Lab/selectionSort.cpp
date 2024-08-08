#include <iostream>
#define maxSize 50

void selectionSort(int *array, int size);
void printArray(int* array, int size);

int main(void){
    int size;
    int array[maxSize];
    std::cout<<"Enter size of array: ";
    std::cin>>size;
    if (size > maxSize){
        std::cout<<"Max size is "<<maxSize<<"\n";
        return 1;
    }
    std::cout<<"Enter elements:\n";
    for (int i = 0; i < size; ++i){
        std::cin>>array[i];
    }

    printArray(array, size);

    selectionSort(array, size);

    printArray(array, size);

    return 0;
}

void printArray(int *array, int size){
    std::cout<<"Array: [ ";
    for (int i = 0; i < size; ++i){
        std::cout<<array[i]<<" ";
    }
    std::cout<<"]\n";
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