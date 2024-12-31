#include "include.hpp"



vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> sol(nums.size(),1);
    int n=nums.size();
    int pre=1;

    for(int i=0;i<n;i++)
    {
        sol[i]*=pre;
        pre*=nums[i];
    }

    pre=1;
    for(int i=n-1;i>-1;i--)
    {
        sol[i] *=pre;
        pre*=nums[i];
    }

    return sol;
}


int main()
{
    iArray x={1,2,3,4},b={-1,1,0,-3,3};

    std::cout<<productExceptSelf(x)<<"\n"<<productExceptSelf(b);
}