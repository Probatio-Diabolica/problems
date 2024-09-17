#include<stdio.h>
int bigga(int *a,int *b){
    if(*a>=*b){
        return *a;
    }else{
        return *b;
    }
}

int maxSubArray(int* nums, int numsSize){
    int sum=0;
    int max=nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        sum=sum+nums[i];
        max=bigga(&max,&sum);
        if(sum<0) sum=0;
    }
    return max;
}

int main(int argc, char **argv){
    
    return 0;
}