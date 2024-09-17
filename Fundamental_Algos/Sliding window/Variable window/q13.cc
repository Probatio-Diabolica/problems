#include<iostream>
#include<vector>
int longestAlternatingSubarray(std::vector<int>& nums, int threshold) 
{
    int left=0,right=0,S=0;
    while(right<nums.size())
    {
        if(nums[right]%2==0)
        {
            left=right;
            ++right;
            break;
        }
    }
    for(int i=left;i<nums.size();i++)
    {
        
    }
}

int main()
{
    
}