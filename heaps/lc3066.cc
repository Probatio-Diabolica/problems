#include"includes.hpp"


int minOperations(vector<int>& nums, long long k) {
    std::priority_queue<long long,std::vector<long long>,std::greater<long long>> heap;
    for(int i=0;i<nums.size();i++)
    {
        heap.push(nums[i]);
    }

    int operations=0;
    while(heap.top()<k)
    {
        long long a=heap.top();
        heap.pop();
        long long b=heap.top();
        heap.pop();
        long long c = (a*2) + b;
        heap.push(c);
        ++operations;
    }
    return operations;
}

int main()
{
    iArray a={1,1,2,4,9};
    std::cout<<minOperations(a,10);
}