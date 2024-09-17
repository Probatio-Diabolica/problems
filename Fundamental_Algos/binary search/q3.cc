#include<iostream>
#include<vector>

void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(std::vector<int> &num,int head,int tail)
{
    int pIndex=head,pivot=nums[head];
    for(size_t i=head+1;i<=tail;i++)
    {
        if(pivot>nums[i])
        {
            ++pIndex;
            swap(&nums[i],&nums[pIndex]);
        }
    }
    swap(&nums[pIndex],&nums[head]);
    return pIndex;
}


void QS(std::vector<int>&num,int head,int tail)
{
    if(head<tail)
    {
        int pivot=partition(num,head,tail);
        QS(num,head,pivot-1);
        QS(num,pivot+1,tail);
    }
}

bool BS(std::vector<int>& arr,int head,int tail)
{
    while(head<tail)
    {
        if()
    }
}

bool checkIfExist(std::vector<int>& arr) 
{
    QS(arr,0,arr.size()-1);
    int head=0;tail=arr.size()-1,mid=head + (tail - head) / 2;
    for(size_t i=0;i<)
    
}
int main()
{
    std::vector<int> a={10,2,5,3};
}
