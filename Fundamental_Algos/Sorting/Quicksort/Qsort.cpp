
#include<vector>
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
