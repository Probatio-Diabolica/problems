/*
!!Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. 
-> It is given that all array elements are distinct.

Note:-  'l' and 'r' denotes the starting and ending index of the array.

// Example 1:

// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given 
// array is 7.
// Example 2:

// Input:
// N = 5
// arr[] = 7 10 4 20 15
// K = 4
// Output : 15

        Explanation :
        4th smallest element in the given 
        array is 15.

Task: You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.


->  Expected Time Complexity: O(n)
->  Expected Auxiliary Space: O(log(n))

Constraints:
        1 <= N <= 105
        1 <= arr[i] <= 105
        1 <= K <= N
 */

#include <iostream>
using namespace std;

void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
}

int partition(int arr[],int head,int tail){
        int pivot=arr[head];
        int index=head;

        for(int i=head+1;i<=tail;i++){
                if(pivot>arr[i]){
                        index++;
                        swap(&arr[index],&arr[i]);//swapped because 
                }
        }
        swap(&arr[index],&arr[head]);
        return index;
}
void Qsort(int arr[],int head,int tail){
        if(head<tail){
                int index=partition(arr,head,tail);
                Qsort(arr,head,index-1);
                Qsort(arr,index+1,tail);
        }
}
void printarr(int arr[],int size){
        for(int i=0;i<size;i++){
                printf("[%d] ",arr[i]);
        }
}

struct couple{
        int min;
        int max;
};

struct couple minMaxSpotWise(int arr[],int place,int size){
        couple miniMax;
        miniMax.min=arr[place-1];
        miniMax.max=arr[size-(place-1)];
        return miniMax;
}
int main(){
        int arr[]={42 , 63 , 123 , 417 , 328 , 590 , 803 , 676 , 608 , 767};
        Qsort(arr,0,9);
        printarr(arr,10);
        int spot=4;
        couple minmax = minMaxSpotWise(arr,spot,9);
        cout<<"\nsmallest "<<spot<<"th is : "<<minmax.min <<" \nwhile the biggest "<<spot<<"th is "<<minmax.max<<endl;
        return 0;
}