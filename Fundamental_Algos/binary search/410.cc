#include<iostream>
#include <vector>


int splitCNT(std::vector<int>& vec,int lim)
{
    int splits =1;
    int cap = 0;
    for(int i : vec)
    {
        if((cap + i ) > lim)
        {
            ++splits;
            cap = 0;
        }
        cap +=i;
    }
    return splits;
}


int splitArray(std::vector<int>& nums, int k) 
{
    int head = 0, tail=0;
    for(int i : nums)
    {
        if(head<i) head=i;
        tail+=i;
    }
    if(k == nums.size()) return head;
    int mid;
    while(head<=tail)
    {
        mid = head + (tail-head)/2;
        if(splitCNT(nums,mid) > k) head = mid + 1;
        else tail = mid - 1; 
    }
    return  head;
}


int main()
{
    std::vector<int> x{7,2,5,10,8};
    std::cout<<splitArray(x, 2);
}