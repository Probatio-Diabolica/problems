#include<iostream>
#include<vector>

void printArr(std::vector<int>& nums)
{
    for(size_t i=0;i<nums.size();i++)
    {
        std::cout<<nums[i]<<" ";
    }
}
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) 
{
    std::vector<int> result={};
    int max=nums[nums.size()-1],previousMax=-1;
    for(size_t i=nums.size()-1;i>nums.size()-k;i--)
    {
        max=max>nums[i] ? max : nums[i];
        if(max > nums[i])
        {
            previousMax=max;
            max=nums[i];
        }
    }
    result.emplace_back(max);
    for(size_t i=nums.size()-2;i>=nums.size()-k;i--)
    {
        
    }
    printArr(result);
    return result;
}

int main()
{
    std::vector<int> a={1,3,-1,-3,5,3,6,7};
    maxSlidingWindow(a,3);
}