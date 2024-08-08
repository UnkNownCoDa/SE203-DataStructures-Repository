#include <iostream>
#define maxSize 50

void insertionSort(int *array, int size);
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

    insertionSort(array, size);

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