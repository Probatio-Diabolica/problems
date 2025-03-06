#include "include.hpp"

int countSubarrays(vector<int>& nums) {
    int solution=0;

    for(int l=0,m=1,r=2;r<nums.size();l++,r++,m++)
    {
        if((nums[l]+nums[r])*2 == nums[m]) ++solution;
    }
    return solution;
}


int main()
{
    iArray a={1,2,1,4,1};
    iArray b={1,1,1};
    std::cout<<countSubarrays(a)<<"\n";
    std::cout<<countSubarrays(b);
}