
#include<stdio.h>

void swap(int* a,int* b){
    int temp =*a;
    *a=*b;
    *b=temp;
}

/*
---------------------------------------------------------------------------------------------------------------------------------------------------------
    !! Partition logic

    task 1: pick an elment from the array, (first elements of  array is generlly the better) call it pivot
    
    task 2: count the no. of elements which are shorter than the pivot. So that we can place the pivot in its spot in the array 
        ->set pivotIndex=count + 1.  
        note: count+1, if the chosen pivot is at the first place in the array
    
    task 3: swap the pivot with the element at the pivotIndex

    task 4: conceptually devide the array into two parts with the pivotIndex being the mid point, let them be A and B. and set the two pointer as i=0, and j=tail.
        note: A will keep the elements smaller than the pivot while B will inhabit the elements bigger than the pivot

    task 5: check and swap the elements which are bigger than pivot from part A with elements smaller than pivot on part B. 
        -> increment i when moving in A and decrement j when moving in B. do both when swap() happens
        note: it is obvious that if any element lies in A is bigger than Pivot then there must be an element in B which is smaller than pivot.

    task 6: stop when i==j and return the index of pivot
        note: this simply means that we have returned 
-------------------------------------------------------------------------------------------------------------------------------------------------------------

*/
int partition(int arr[],int head, int tail){
    int pivot=arr[head];
    int index=head;
    for(int i=head+1;i<=tail;i++){
        if(pivot>arr[i]){
            index++;
            swap(&arr[i],&arr[index]);
        }
    }
    swap(&arr[index],&arr[head]);
    return index;
}

void Qsort(int arr[],int head, int tail){
    if(head<tail){
        int index=partition(arr,head,tail);
        Qsort(arr,head,index-1);
        Qsort(arr,index+1,tail);
    }
}

void printarr(int arr[],int size){
    for (int i = 0; i < size; i++)
    {   
        (i==0) ? printf("["):printf(",");
        printf(" %d",arr[i] );
        (i==size-1) ? printf("]\n"):printf("");
    }
    
}
int main(){
    int arr[]={7,7,3,5};
    Qsort(arr,0,4);
    printarr(arr,4);
    return 0;
}