#include<stdio.h>

/*
!! Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

// Examples:

// Input: arr[] = {3, 5, 4, 1, 9}
// Output: Minimum element is: 1
//         Maximum element is: 9

// Input: arr[] = {22, 14, 8, 17, 35, 3}
// Output: Minimum element is: 3
//         Maximum element is: 35

*/

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        (i==0) ? printf("["):printf("");
        printf("%d",arr[i]);
        (i==size-1) ? printf("]\n") : printf(",");
    }
}

// Approach a
void minMax(int arr[],int size){
    int max=arr[0];
    int min=arr[0];
    
    for(int i=1;i<size;i++){
       if(max<arr[i]) {
            max=arr[i];
        }else if (min>arr[i])
        {
            min=arr[i];
        }
        
    }

    printf("max is %d", max);
    printf(" Min is : %d", min);
}

// Approach B
struct Pair{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int size){ //* in C , we need to use struct keyword for using a struct defined data-type
    struct Pair minMax;

    minMax.min=arr[0];
    minMax.max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]<minMax.min){
            minMax.min=arr[i];
        }else if (arr[i]>minMax.max)
        {
            minMax.max=arr[i];
        }
        
    }
    return minMax;
}


int main(){
    int arr[]={13 , 3 , 914 , 824 , 143,123,8901};
    printarr(arr , 5);
    //minMax(arr,5);
    struct Pair mm=getMinMax(arr,7);
    printf("%d\n",mm.max);
    printf("%d",mm.min);
    
    return 0;
}