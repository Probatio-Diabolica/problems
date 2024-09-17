#include<iostream>
#include<vector>


int longestSubarray(std::vector<int>& nums)
{
    int left=0,zero=0,winSize=0;
    for(size_t i=0;i<nums.size();++i)
    {
        zero+=(nums[i]==0);
        while(zero>1)
        {
            zero-=(nums[left]==0);
            left++;
        }
        winSize=winSize>(i-left) ? winSize : (i-left);
    }
    return winSize;
}

int main()
{
    std::vector<int> a={1,0,1,1,1,1,1,0,1,1,1};
    std::vector<int> b={0,1,1,1,0,0,1,1,0};
    std::vector<int> c={1,1,1};
    std::cout<<longestSubarray(b)<<"\n";
    std::cout<<longestSubarray2(b);
}