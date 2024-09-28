#include"includes.hpp"

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> sol(nums.size(),1);

    //pre
    int pre=1;
    for(int i=0;i<nums.size();i++)
    {
        sol[i]=pre;
        pre*=nums[i];
    }

    // post
    pre = 1;
    for(int i=nums.size()-1;i>-1;i--)
    {
        sol[i]*=pre;
        pre*=nums[i];
    }
    return sol;
}

int main()
{
    std::vector<int> sol(6,1);
    std::cout<<sol;
}