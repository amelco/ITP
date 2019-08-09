#include <stdio.h>

int main(){
    int nums[10];
    int tmp;

    for(int i=0; i<10; i++){
        scanf("%d", &nums[i]);
    }

    for(int n=0; n<10; n++){
        for(int j=n+1; j<10; j++){
            if (nums[j] < nums[n]){
                tmp = nums[j];
                nums[j] = nums[n];
                nums[n] = tmp;
            }
        }
    }

    for(int i=0; i<10; i++){
        printf("%d ", nums[i]);
    }

    printf("\n");
}