/* 
* @brief Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

// Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

*/ 


#include<iostream>
#include<vector>

int min(int a, int b)
{

    return a>=b ? b:a;
}

int minSubArrayLen(int target, std::vector<int>& nums) 
{
    int lenght=-1 ,sum=0,winB=0,winE=-1,minLenght=0;
    for(size_t i=0;i<nums.size() && sum <= target;i++)
    {
        sum+=nums[i];
        lenght++;
        winE++;
    }
    for(size_t i=1;i<nums.size();i++)
    {
        if(sum-=nums[winB] >=target)
        {
            sum-=nums[winB];
            winB++;
            if(min(lenght,winE-winB)!=lenght) minLenght =winE-winB;
        }
        if (sum+=nums[i] >=target)
        {
            sum+=nums[i];
            winE++;
            if(min(lenght,winE-winB)!=lenght) minLenght =winE-winB;
        }
    }
    return minLenght;
}

int main()
{
    std::vector<int> vec={1,2,3,4,5,6};
    std::cout<<minSubArrayLen(600,vec);
    // std::cout<<min(11,11);
}