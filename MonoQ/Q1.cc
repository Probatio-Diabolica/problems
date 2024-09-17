#include"include.h"


int maxSubarraySumCircular(std::vector<int>& nums) 
{
    int len=nums.size()*2,sum=nums[0],winSum=nums[0];
    for(size_t left=0;left<len/2;left)
    {
        size_t right=left+1;
        winSum=nums[left%nums.size()];
        while(right<len)
        {
            size_t gap=nums.size()-1;
            winSum+=nums[right%nums.size()];
            if(winSum <sum or gap<0 ) break;
            sum=(sum>winSum) ? sum : winSum;
            ++right;
            --gap;
        }
        left=right+1;
    }
    return sum;
}

int main()
{
    std::vector<int> a={1,-2,3,-2};
    std::vector<int> b={5,-3,5};
    std::vector<int> c={-3,-2,-3};
    std::cout<<maxSubarraySumCircular(a)<<"\n";
    std::cout<<maxSubarraySumCircular(b)<<"\n";
    std::cout<<maxSubarraySumCircular(c)<<"\n";
}