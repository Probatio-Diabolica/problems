#include"includes.hpp"

int subarraysWithKDistinct(std::vector<int>& nums, int k) 
{
    std::unordered_map<int,int> count;
    int left=0,centroid=0,result=0,right=0;
    for(int right=0;right<nums.size();right++)
    {
        ++count[nums[right]];
        while(count.size()>k)
        {
            count[nums[centroid]]--;
            if(count[nums[centroid]]==0) count.erase(nums[centroid]);
            left=++centroid;
        }
        while(count[nums[centroid]]>1) count[nums[centroid++]]--;
        if(count.size()==k) result+=centroid-left +1;

    }

    return result;
}

int main()
{
    std::vector<int> a={2,2,1,2,2,2,1,1};
    std::vector<int> b={1,2,1,3,4};
    
    std::cout<<subarraysWithKDistinct(a,2)<<"\n";
    std::cout<<subarraysWithKDistinct(b,3);
    return 0;
}