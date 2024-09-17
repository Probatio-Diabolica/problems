#include<iostream>
#include<unordered_map>
#include<vector>
//// TC:O(N) SC:O(N)
// int singleNumber(std::vector<int>& nums) 
// {
//     std::unordered_map<int,int> map;
//     for(size_t i=0;i<nums.size();i++) map[nums[i]]++;
//    for(const auto& m:map) if(m.second==1) return m.first;
//     return 0;
// }
////better one
// TC:O{N} && SC:O(1)
// //form observations, we have seen that or just adds the odd occurred items and subtracts the even occurered items
// 
int singleNumber(std::vector<int>& nums) 
{
    int ans=0;
    for(auto num:nums)
    {
        ans^=num;
        std::cout<<ans<<"\n";
    }
    return ans;
}
int main()
{
    std::vector<int> a={2,2,1};
    std::vector<int> b={4,1,2,1,2};
    std::vector<int> c={1};
    // std::cout<<singleNumber(a)<<"\n";
    std::cout<<singleNumber(b)<<"\n";
    // std::cout<<singleNumber(c)<<"\n";
}