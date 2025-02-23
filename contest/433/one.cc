#include"include.hpp"

int subarraySum(vector<int>& nums) 
{
    vector<int> prefix(nums.size(),0);
    int sol=0;
    for(int i =0;i<nums.size();i++)
    {
        sol+=nums[i];
        prefix[i]=sol;
    }

    sol=0;
    int start;
    auto max = [](int a, int b){ return a>b ? a : b;};
    
    for(int i=0;i<nums.size();i++)
    {
        start= max(0,i - nums[i]);
        if(start>0) sol += prefix[i] - prefix[start-1];
        else sol+=prefix[i]; 
    }

    return sol;
}


int main()
{
    iArray a={3,1,1,2};
    std::cout<<subarraySum(a);
}