/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

 

Constraints:

    1 <= target <= 109
    1 <= nums.length <= 105
    1 <= nums[i] <= 104

 
Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/ 


#include<iostream>
#include<vector>

int minSubArrayLen(int target, std::vector<int>& nums)
{
    int sum=0,right=0,best=0;
    for(size_t i=0;i<nums.size() && sum<target;i++)
    {
        sum+=nums[i];
        right++;
    }
    if(sum<target) return 0;
    best=right;
    for(size_t left=1;left<nums.size();left++)
    {
        sum-=nums[left-1];
        while(right!=nums.size() && target>sum)
        {
            sum+=nums[right];
            right++;
        }
        if(sum>=target) best = best>(right-left)? (right-left) : best;
    }
    return best;
}

int main()
{
    std::vector<int> a={2,3,1,2,4,3};
    std::vector<int> b={1,4,4};
    std::vector<int> c={1,1,1,1,1,1,1,1};
    std::vector<int> d={1,2,3,4,5};
    std::cout<<minSubArrayLen(7,a)<<"\n";
    std::cout<<minSubArrayLen(4,b)<<"\n";
    std::cout<<minSubArrayLen(11,c)<<"\n";
    std::cout<<minSubArrayLen(15,d)<<"\n";
}