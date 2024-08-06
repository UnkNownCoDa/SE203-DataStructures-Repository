#include <stdio.h>

int sum(int *nums, int size){
    if (size <=1){
        return nums[size-1];
    }
    return nums[size-1] + sum(nums, size-1);
}

int main(){
    int nums[] = {3, 4, 1, 5, 2};
    int total;
    total = sum(nums, sizeof(nums)/sizeof(nums[0]));
    printf("%d\n", total);
    return 0;
}
