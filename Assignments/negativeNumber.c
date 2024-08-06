#include <stdio.h>

int main(){
    int nums[] = {3, -4, 1, -5, 2};
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++){
        if (nums[i] < 0){
            printf("%d\n", nums[i]);
        }
    }
    return 0;
}
