#include<stdio.h>



int maxSubArray(int* nums, int numsSize) {
    int sum=0;
    int curr=0;
    int point=0;
    while(point<numsSize){
        for (int i = point; i < numsSize; i++)
        {
            curr=curr+nums[i];
            if(curr>sum) sum=curr;
        }
        curr=0;
        point++;
    }
    

    return sum;
}

int main(int argc, char **argv){
    int nums[] = {5,4,-1,7,8};
    printf("%d \n",maxSubArray(nums,5));
    return 0;
}