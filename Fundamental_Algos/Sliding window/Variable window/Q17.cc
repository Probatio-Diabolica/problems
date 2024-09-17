#include<iostream>
#include<vector>

int findMaxConsecutiveOnes(std::vector<int>& nums) 
{
    int tail=0,winSize=0,maxi=0;
    while(tail<nums.size())
    {
        (nums[tail]==1) ? ++winSize : winSize=0; 
        maxi=(maxi>winSize) ? maxi :winSize;
        tail++;
    }
    return maxi;
}

int main()
{
    std::vector<int> a={1,1,0,1,1,1};
    std::vector<int> b={1,0,1,1,0,1};
    std::vector<int> c={1,1,1,1,1,1,1,1};
    std::cout<<findMaxConsecutiveOnes(a)<<"\n";
    std::cout<<findMaxConsecutiveOnes(b)<<"\n";
    std::cout<<findMaxConsecutiveOnes(c)<<"\n";
    // std::cout<<findMaxConsecutiveOnes()<<"\n";
}