#include <iostream>
#define maxSize 50

void bubbleSort(int *array, int size);
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

    bubbleSort(array, size);

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