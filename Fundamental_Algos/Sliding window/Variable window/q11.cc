/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 109
    0 <= limit <= 109

*/ 

#include<iostream>
#include<vector>

int longestSubarray(std::vector<int>& nums, int limit) 
{
    int maxSize=1;
    size_t right=0;
    for(size_t left =0;left <nums.size()-1 && right != nums.size();left++)
    {
        int window=1,min=nums[left],max=nums[left];
        right=left+1;
        while((nums[left]==nums[right] ) and right<nums.size())
        {
            window++;
            right++;
        }
        while((nums[left]!=nums[right] ) and right<nums.size())
        {
                max= max>nums[right] ? max : nums[right];
                min = min < nums[right] ? min :nums[right];
                if((max-min) <= limit) window++;
                else break;
                right++;
        }
        
        maxSize = maxSize > window ? maxSize : window;
    }
    return maxSize;
}

int main()
{
    std::vector<int> a={8,2,4,7};
    std::vector<int> b = {10,1,2,4,7,2};
    std::vector<int> c={1,5,6,7,5,3};
    std::vector<int> d = {4,2,2,2,4,4,2,2};

    std::cout<<longestSubarray(a,4)<<"\n";
    std::cout<<longestSubarray(b,5)<<"\n";
    std::cout<<longestSubarray(c,2)<<"\n";
    std::cout<<longestSubarray(d,0)<<"\n";
}