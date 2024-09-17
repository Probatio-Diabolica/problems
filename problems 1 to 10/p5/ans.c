#include<stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void shifting(int* nums, int numsSize) {
    int head=0;
    int curr=0;
     
    while(curr<=numsSize-1){
        if(nums[curr]<0){
            swap(&nums[curr],&nums[head]);
            head++;
            curr++;
        }else{
            curr++;
        }
    }
}
void printarr(int * nums,int size){
    for (int i = 0; i < size; i++)
    {
        if(i==0){
            printf("[ %d ,", nums[i]);
        }else if(i==size-1){
            printf("%d ]", nums[i]);
        }else{
            printf("%d ," ,nums[i]);
        }
    }
    
}
int main(){
int arr[]={-12, 11, -13, -5, 6, -7, 5, -3, -6};//result: -12, -13 ,-5 ,-7 ,-3 ,-6 ,11 ,6, 5
printarr(arr,9);
shifting(arr,9);
printarr(arr,9);
return 0;
}