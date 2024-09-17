#include<stdio.h>
int search(int* arr,int head,int tail){
    int mid=head + (tail-head)/2;
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
        return mid;
    }else if((arr[mid]>arr[mid-1] )){
        //head=mid+1;
        return search(arr,mid+1,tail);
    }else{
        //tail=mid-1;
        return search(arr,head,mid-1);
    }
}
int peakIndexInMountainArray(int* arr, int arrSize) {

    int index=search(arr,1,arrSize-2);
    return index;
}

int main(int argc, char **argv){
    int arr[]={3,5,3,2,0};
    printf("ans : %d", peakIndexInMountainArray(arr,5));
    return 0;
}