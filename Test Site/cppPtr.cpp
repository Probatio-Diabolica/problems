#include <iostream>
void swap(int& a,int&b)
{
    int temp=a;a=b;b=temp;
}


void swapAlternate(int *arr, int size)
{
    int head=0,tail=size-1;
    while (head<=tail-1)
    {
        swap(arr[head],arr[head+1]);
        head+=2;
    }       
}
int main(int argc, char **argv)
{
    // int a=10,b=90;
    // swap(&a,&b);
    int arr[6]={1,2,3,4,5,6};
    swapAlternate(arr,6);
    std::cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<" ";
    std::cin.get();
}