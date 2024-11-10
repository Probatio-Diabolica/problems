#include"includes.hpp"



int subarraySum(std::vector<int>& nums, int k) 
{
    int prefixSum=0,count=0;
    std::unordered_map<int,int> mp;
    mp[0]=1;
    for (int i: nums)
    {
        prefixSum+=i;
        count+=mp[prefixSum-k];
        mp[prefixSum]+=1;
    }
    return count;
}


int main()
{
    std::vector<int> a={1,2,3,-3,1,1,1,4,2,-3};
    std::cout<<subarraySum(a,3);
}