/*
!!  Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


// Example 1:

// Input: 
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated 
// into ascending order.
// Example 2:

// Input: 
// N = 3
// arr[] = {0 1 0}
// Output:
// 0 0 1
// Explanation:
// 0s 1s and 2s are segregated 
// into ascending order.


task: You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


-> Expected Time Complexity: O(N)
-> Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2


*/
#include<stdio.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//approach A, it is slow
void sortColors(int* nums,int numsSize){
    for(int i=1;i<numsSize;i++){
            if(i>0 && i<numsSize-1)
            {
                if(nums[i]>nums[i+1]){
                    swap(&nums[i],&nums[i+1]);
                    i=i-2;
                }
                else if(nums[i]<nums[i-1]){
                    swap(&nums[i],&nums[i-1]);
                    i=i-2;
                }
            }else{
                if(i==0){
                    if(nums[i+1]<nums[i]) swap(&nums[i+1],&nums[i]);
                }
                else{
                    if(nums[i-1]>nums[i]) swap(&nums[i-1],&nums[i]);
                }
            }
    }
    
}




void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        if(i==0){
            printf("[ %d",arr[i]);
        }
        else if(i!=0 && i<size-1){
            printf(", %d",arr[i]);
        }else{
            printf(",%d ]",arr[i]);
        }
    }
}
int main(){
    int x=9;
    int y=0;
    // swap(&x,&y);
    // printf("a=%d",x);
    // printf(" b=%d",y);
    int arr[]= {2,0,2,1,0,0};
    printarr(arr,6);
    printf("\n");
    sortColors(arr,6);
    printarr(arr,6);
    // sort(arr,5);
    // printf("\n");
    // printarr(arr,5);
    return 0;
}