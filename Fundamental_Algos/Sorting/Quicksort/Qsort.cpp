#include<iostream>
#include<vector>
#define val 10
void swap(int *a,int*b)
{
   int temp =*a;
    *a=*b;
    *b=temp;
    // *a+=*b;
    // *b=*a-*b;
    // *a=*a-*b;
}

int pivot(std::vector<int> & arr,int head,int tail)
{
    int pivot=arr[head];
    int index=head;
    for(int i=head+1;i<=tail;i++){
        if(pivot>arr[i])
        {
            index++;
            swap(&arr[i],&arr[index]);
        }
    }
    swap(&arr[index],&arr[head]);
    return index;
}


void QS(std::vector<int> &arr,int head,int tail)
{
    if(head<tail){
        int index=pivot(arr,head,tail);
        QS(arr,head,index-1);
        QS(arr,index+1,tail);
    }
}

int main()
{
    // std::vector<int> a={4,6,5,7};
    // QS(a,0,a.size()-1);
    // std::cout<<a[0]<<"\n";
    std::string a="abc";

    if(a[0])
    {
        std::cout<<a[0];
    }
#if  a ==false
    std::cout<<a[0];
#endif
}