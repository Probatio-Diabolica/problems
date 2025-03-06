#include"include.hpp"

int min(int a, int b)
{
    return a > b ? a : b; 
}

int maxAdjacentDistance(vector<int>& nums)
{
    int sol= INT32_MIN;

    for(int i = 0;i < nums.size();i++) sol = min(sol,std::abs(nums[i]-nums[((nums.size()-1) + i )%nums.size()]));

    return sol;
}

int main()
{
    iArray arr={-5,-10,-5},brr={6,2,4,16};
    std::cout<<maxAdjacentDistance(arr)<<'\n'<<maxAdjacentDistance(brr);
}