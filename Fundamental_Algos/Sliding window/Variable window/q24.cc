#include "includes.hpp"

int numberOfSubarrays(std::vector<int>& nums, int k) 
{
    int result=0, odds=0,l=0,m=0;
    for(int r=0;r<nums.size();r++)
    {
        if(nums[r]%2==1) odds++;

        while(odds>k)
        {
            if(nums[l]%2==1) odds--;
            l++;
            m=l;
            if( odds==k) 
            {
                while (nums[m]%2==0) ++m;
                result+=(m-l)+1;
            }
        }
        
    }
    return result;
}
int main()
{
    std::vector<int> a={2,2,2,1,2,2,1,2,2,2};
    std::cout<<numberOfSubarrays(a,2);
    // std::cout<<true;
}

//https://app.careerpuck.com/job-board/atlan/job/258b1aad-cef9-4f89-8c66-3aac988de02c