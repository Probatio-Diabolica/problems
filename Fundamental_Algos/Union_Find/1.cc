#include "includes.hpp" 


int longestConsecutive(std::vector<int>& nums) 
{
    if(nums.size()==0) return 0;
    std::unordered_set<int>  set;
    for(int el:nums) set.insert(el);
    int longest=1;
    for(int el: set)
    {
        if(!set.contains(el-1))
        {
            int count=1;
            int curr=el;
            {
                while(set.contains(++curr)) curr++;
                if(longest<count) longest=count;
            }
        }
    }
    return longest;
}
int main()
{
    std::vector<int> a={100,4,200,1,3,2};
    std::cout<<longestConsecutive(a);
}