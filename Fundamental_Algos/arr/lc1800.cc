#include"includes.hpp"


int maxAscendingSum(vector<int>& nums) {
    int sum=nums[0],maxSum=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]>nums[i-1])
        {
            sum+=nums[i];
            maxSum= max(sum,maxSum);
        }else
        {
            sum=nums[i];
        }
    }
    return maxSum;
}

int main()
{
    iArray x={10,20,30,40,50};
    std::cout<<maxAscendingSum(x);
}