#include<stdio.h>
/*
-> Given an array (or string), the task is to reverse the array/string.
// Examples : 


// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

// Input :  arr[] = {4, 5, 1, 2}
// Output : arr[] = {2, 1, 5, 4}
*/ 
void printarr(int arr[],int size){
    for (int i = 0; i < size; i++)
    {   
        (i==0) ? printf("["):printf(",");
        printf(" %d",arr[i] );
        (i==size-1) ? printf("]\n"):printf("");
    }
    
}
void swap(int *a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;

}

void reverse(int arr[],int start,int end){
    int temp=0;
    while (start<end){
        swap(&arr[start],&arr[end]);
        start++;
        end--;
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    printarr(arr,5);
    reverse(arr,0,4);
    printarr(arr,5);
    return 0;
}