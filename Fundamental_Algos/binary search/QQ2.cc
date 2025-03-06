#include<iostream>
#include<vector>
// #include<bits\stdc++.h>
std::ostream& operator<<(std::ostream &stream,std::vector<int> vec)
{
    for(int i:vec) stream<<i<<" , ";
    return stream;
}

void swap(int *a, int *b)
{
    // *a ^= *b;
    // *b ^= *a;
    // *a ^= *b;
    int temp=*a;
    *a=*b;
    *b=temp;
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

void QS(std::vector<int> &vec,int head,int tail)
{
    if(head<tail)
    {
        int partition = pivot(vec,head,tail);
        QS(vec,head,partition-1);
        QS(vec,partition+1,tail);
    }
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
{
    QS(nums,0,nums.size()-1);
    int n=nums.size();
    std::vector<std::vector<int>> sol{};
    for(int l=0;l<=n-3;l++)
    {
        if(l>0 and (nums[l]==nums[l-1])) continue;
        int LL=l+1,RR=nums.size()-1;
        while(LL<RR)
        {
            int sum=nums[l]+nums[RR]+nums[LL];
            if(sum==0) 
            {
                sol.push_back(std::vector<int>{nums[l],nums[LL],nums[RR]});
                ++LL;
                while (nums[LL]==nums[LL-1] and LL<RR) ++LL;
            }
            else if(sum>0) --RR;       
            else ++LL;
            
        }
    }
    return sol;
}

int main()
{
    std::vector<int> a={-1,0,1,2,-1,-4};
    threeSum(a);
    
    // QS(a,0,a.size()-1);
    // std::cout<<a;
}
