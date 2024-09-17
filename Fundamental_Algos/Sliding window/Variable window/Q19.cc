#include"includes.hpp"

int max(std::vector<int>& nums)
{
    int max=0;
    for(int a:nums) if(a>max) max=a;
    return max;
}

long long countSubarrays(std::vector<int>& nums, int k) 
{
    int left=0,result=0,maxi=max(nums),count=0;
    for(int right=0;right<nums.size();right++)
    {
        if(nums[right]==maxi) ++count;
        while(count==k)  if(nums[left++]==maxi) --count;
        result+=left;
    }
    return result;
}
int main()
{
    std::vector<int> a={1,2,3,2,1};
    std::vector<int> b={1,2,3,2,3,3};
    std::vector<int> c={1,3,2,3,3};
    std::cout<<countSubarrays(a,2)<<"\n";
    std::cout<<countSubarrays(b,2)<<"\n";
    std::cout<<countSubarrays(c,2);
}