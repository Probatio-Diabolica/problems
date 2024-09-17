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

#include <stdio.h>

struct miniMax{
    int min;
    int max;    
};


void kthElement(struct miniMax* minMax,int arr[],int spot,int size){
    minMax->min=arr[spot-1];
    minMax->max=arr[(size-1)-(spot-1)];
}



void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int head, int tail) {
    int Pivot = arr[head];
    int pivotIndex = head;


    for (int i = head + 1; i <= tail; i++) {
        if (Pivot >= arr[i]) {
            pivotIndex++;
            swap(&arr[pivotIndex], &arr[i]);
            /*
            !! Here's a step-by-step explanation of what this code does:

            -> The loop iterates over the elements in the sub-array from head + 1 to tail. 
            $  The for loop is responsible for examining each element in the sub-array.

            -> For each element at index i, it checks whether the element is less than or equal to the pivot element, which is stored in Pivot.

            -> If the element at index i is indeed less than or equal to the pivot, the pivotIndex is incremented, indicating that a new element smaller than the pivot has been found. 
            $ It effectively moves the boundary between elements smaller and greater than the pivot to the right.

            -> The swap function is called to exchange the positions of the element at index pivotIndex with the element at index i. This swap operation ensures that the smaller or equal elements end up on the left side of the pivotIndex, and the greater elements remain on the right.

            -> This loop effectively partitions the sub-array into two parts: the left part contains elements less than or equal to the pivot, and the right part contains elements greater than the pivot. The pivotIndex keeps track of the boundary between these two sections, and the swap operation rearranges elements as needed.

            -> By the end of this loop, the pivot element is moved to its final sorted position (between the smaller and greater elements), and the array is partially partitioned. This process contributes to the overall sorting of the entire array through recursive calls to Quicksort.

            note: The key idea here is that it efficiently divides the sub-array into two parts without explicitly sorting the entire array yet, which is the essence of the Quicksort algorithm's efficiency.
            */
        }
    }

    swap(&arr[head], &arr[pivotIndex]);

    // Now the pivot element is in its final sorted position
    return pivotIndex;
}


void Qsort(int arr[],int head,int tail){
    //head=begining of array(actual number) tail=end of array[actual number]
    if(head<tail+1){
    int index=partition(arr,head,tail);
    Qsort(arr,head,index-1);
    Qsort(arr,index+1,tail);
    }
    
}

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("[%d]", arr[i]);
    }
}

int main(){
    int arr[]={42 , 63 , 123 , 417 , 328 , 590 , 803 , 676 , 608 , 767};
        printarr(arr,10);
        printf("\n");printf("\n");
        Qsort(arr,0,9);
        
        //printarr(arr,10);
        printf("\n");
        int spot=4;
        int size=10;
        struct miniMax mm;
        kthElement(&mm,arr,spot,size);

        printf("\nmax at 4th is: %d",mm.max);
        printf("\nmin at 4th is: %d",mm.min);
    return 0;
}