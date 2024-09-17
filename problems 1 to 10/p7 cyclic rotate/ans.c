#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void reverse(int* arr, int head,int tail){
    while(head<tail){
        swap(&arr[head],&arr[tail]);
        head++;
        tail--;
    }
}

void rotate(int* arr, int size,int key){
    key=key%size;
    reverse(arr,0,size-1);
    reverse(arr,0,key-1);
    reverse(arr,key,size-1);
}

void printarr(int* nums,int size){
    for (int i = 0; i < size; i++)
    {
        if(i==0){
            printf("[ %d,", nums[i]);
        }else if(i==size-1){
            printf(" %d ]", nums[i]);
        }else{
            printf(" %d," ,nums[i]);
        }
    }
    
}
int main(int argc, char *argv[]){
    int arr[]={1,2,3,4,8,7};

    rotate(arr,6,2);
    printarr(arr,6);

    return 0;
}