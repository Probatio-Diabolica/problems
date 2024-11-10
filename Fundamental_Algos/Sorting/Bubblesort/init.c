#include<stdio.h>
#define max_size 100
void swap(int* a, int* b)
{
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

void bubblesort(int arr[max_size],int size)
{
    for(size_t left=0;left<size-1;left++)
    {
        for(size_t right=left+1;right<size;right++)
        {
            if(arr[right]<arr[right-1]) swap(&arr[right],&arr[right-1]);
        }
    }
}

void printArr(int arr[max_size],int size)
{
    for(size_t i=0;i<size;i++) printf("%d",arr[]);
        {
            if(arr[right]<arr[right-1]) swap(&arr[right],&arr[right-1]);
        }
}
int main()
{
    int a=10,b=90;
    swap(&a,&b);
    printf("%d\n",b);

    int arr[5]={1,2,3,4,5};
    bubblesort(arr,5);
    printf("%d",arr[0]);
}