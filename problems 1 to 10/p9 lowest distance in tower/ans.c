#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int *arr,int head,int tail){
    int index=head;
    int pivot=arr[head];
    for (int i = head+1; i <=tail; i++)
    {
        if(arr[i]<pivot){
            index++;
            swap(&arr[i],&arr[index]);
        }
    }
    swap(&arr[index],&arr[head]);
    return index;
}

void Qsort(int *arr, int head,int tail){
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
int getMinDiff(int *arr, int n, int k){
    Qsort(arr,0,n);
    printarr(arr,n);
    for(int i=0;i<n;i++){
        if(i<=(n-1)/2)
        {
            arr[i]=arr[i]+k;
        }else{
            arr[i]=arr[i]-k;
        }
    }
    
    return arr[n-1]-arr[0];
}

int main(int argc, char **argv){
    int arr[]={7,7,3,5};
    printf("%d",getMinDiff(arr,4,1));
}