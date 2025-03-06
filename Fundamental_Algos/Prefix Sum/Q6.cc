#include"includes.hpp"
int findMiddleIndex(std::vector<int>& nums) 
{
    if(nums.size()==1) return 0;
    int left=0,right;
    std::vector<int> sol(nums.size(),0);
    for(short int i =0;i<nums.size();i++)  sol[i]= ((i-1)<0 ? 0 +nums[i] : sol[i-1]+nums[i]);
    right=sol[sol.size()-1] - sol[0];
    for(short int i =0;i<nums.size();i++) 
    {
        if(left==right) return i;
        left=sol[i]; 
        ((i+1)>nums.size()-1)? right=0 : right=sol[sol.size()-1] - sol[i+1]; 
    }
    return -1;
}

int main()
{
    std::vector<int> a={1,2,3,4,5};
    std::vector<int> b={2,3,-1,8,4};
    std::vector<int> c={1,-1,4};
    std::vector<int> d={2,5};
    std::cout<<findMiddleIndex(a)<<"\n";
    std::cout<<findMiddleIndex(b)<<"\n";
    std::cout<<findMiddleIndex(c)<<"\n";
    std::cout<<findMiddleIndex(d)<<"\n";
}