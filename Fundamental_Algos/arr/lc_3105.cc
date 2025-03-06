#include"includes.hpp"

int longestMonotonicSubarray(vector<int>& nums) {
    int li=0,ri=0;
    int ld=0,rd=0;
    int sol=1;
    auto max=[](int a, int b) 
    {
        return a>b? a: b;
    };
    for(int i = 0;i <nums.size()-1;i++)
    {
        if(nums[i]<nums[i+1])
        {
            ++ri;
            sol=max(sol,(ri-li)+1);
            ld=i,rd=i;
        }
        else if(nums[i] > nums[i+1])
        {
            ++rd;
            sol=max(sol,(rd-ld)+1);

            li=i,ri=i;
        }
        else {
            li = i, ri =i , ld = 0, rd = 0;
        }
    }
    return sol;
}

int main()
{
    iArray x={1,4,3,3,2};
    std::cout<<longestMonotonicSubarray(x);
}