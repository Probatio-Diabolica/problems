/*
CONTAINS DUPLICATE 2:
!! Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

*/ 
#include<iostream>
#include<vector>
#include<unordered_map>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int,size_t> map;
    // int distance;
    for(size_t current=0;current<nums.size();current++)
    {
        // distance = current-map[nums[current]];
        // THis one instruction (above this) fucked the whole code. why?
        if(map.find(nums[current])!=map.end() && current-map[nums[current]]<=k) return true;
        map[nums[current]]=current;
    }
    return false;        
}
int main()
{
    std::vector<int> vec={1,2,1,1,1};
    std::vector<int> vec2={1,2,1,1,1};
    std::vector<int> vec3={1,2,1,1,1};
    std::vector<int> vec4={1,2,3,1,2,3};
    std::cout<<containsNearbyDuplicate(vec4,2)<<"\n";

}