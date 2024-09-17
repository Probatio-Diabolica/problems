#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int head, int tail) {
    int Pivot = arr[head];
    int pivotIndex = head;
    int low = head + 1;
    int high = tail;

    for (int i = head + 1; i <= tail; i++) {
        if (Pivot >= arr[i]) {
            pivotIndex++;
            swap(&arr[pivotIndex], &arr[i]);
            /*If an element arr[i] is less than or equal to the pivot, the pivotIndex is incremented, and the element at arr[i] is swapped with the element at arr[pivotIndex]. This step ensures that elements less than or equal to the pivot end up on the left side of the pivot, and elements greater than the pivot end up on the right side.*/
        }
    }

    swap(&arr[head], &arr[pivotIndex]);

    // Now the pivot element is in its final sorted position
    return pivotIndex;
}

// int partition(int arr[], int low, int high) {
//     int pivot = arr[low];
//     int i = low + 1;
//     int j = high;

//     while (1) {
//         while (i <= j && arr[i] <= pivot)
//             i++;
//         while (arr[j] >= pivot && j >= i)
//             j--;

//         if (i <= j)
//             swap(&arr[i], &arr[j]);
//         else
//             break;
//     }

//     swap(&arr[low], &arr[j]);
//     return j;
// }
void Qsort(int arr[],int head,int tail){
    //head=begining of array(actual number) tail=end of array[actual number]
    if(head<tail+1){
    int index=partition(arr,head,tail);
    Qsort(arr,head,index-1);
    Qsort(arr,index+1,tail);
    }
    
}
int main(){
    int arr[]={9487,54,324,544,32,3};
    Qsort(arr,0,5);
    // int a=10;
    // int b=3;
    // swap(&a,&b);
    // printf("a=10 but is %d",a,"b = 3 but is %d",b);
    printf("Sorted array: ");
    for (int i = 0; i < 6; i++) {
        printf("%d , ", arr[i]);
    }
    return 0;
}