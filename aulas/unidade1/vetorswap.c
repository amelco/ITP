#include <stdio.h>

int main(){
    int nums[20];
    int tmp;

    for (int i=0; i<20; i++){
        scanf("%d", &nums[i]);
    }
    for (int i=0; i<10; i++){
        tmp = nums[i];
        nums[i] = nums[19-i];
        nums[19-i] = tmp;
    }
    for (int i=0; i<20; i++){
        printf("N[%d] = %d\n", i, nums[i]);
    }

    return 0;
}