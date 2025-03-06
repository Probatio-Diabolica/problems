#include"includes.hpp"

bool checkSubarraySum(std::vector<int>& nums, int k) 
{
    std::unordered_map<int,int> map;
    map[0]=-1;
    int prefixSum=0;
    for(size_t i=0;i<nums.size();i++)
    {
        prefixSum+=nums[i];
        if(map.contains(prefixSum%k) and (i-map[prefixSum%k])>1) return true;
        if(! map.contains(prefixSum%k)) map[prefixSum%k]=i;
    }
    return false;        
}

int main()
{
    std::vector<int> a={23,2,4,6,7},b={0,2,0,3,0,3,7};
    std::cout<<checkSubarraySum(a,6)<<"\n"<<checkSubarraySum(b,1)<<"\n";
}