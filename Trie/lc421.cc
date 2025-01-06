#include"includes.hpp"


int findMaximumXOR(const vector<int>& nums) {
        
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }
        return nums[0]^nums[1];
}




int main()
{
    cout<<findMaximumXOR({3,10,5,2,2,8});
}