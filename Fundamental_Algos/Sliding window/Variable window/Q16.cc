#include<iostream>
#include<vector>
// https://www.youtube.com/watch?v=tcPwlznFnFs
// better solution
int longestSubarray(std::vector<int>& nums, int limit)
{
    int right=0,left=0,len=0,count=0,smol=nums[0],big=nums[0],next=-1;
    while(right<nums.size())
    {
        if(std::abs(big-smol)>limit /*or std::abs(nums[left]-nums[right]) >limit*/ )
        {
            if(next>left and next<nums.size()) left=next;
            else left++;
            
            right=left;
            count=0;
            smol=nums[right];
            big=nums[right];
        }
        else
        {
            if(nums[right]==nums[next] and next >-1) next++;
            right++;
            count++;

        }
        if(right<nums.size())
        {
        smol=(smol<nums[right])? smol:nums[right];
        big=(big>nums[right])? big:nums[right];
        }
                len=(len>count) ? len:count;

    }
    return len;
}

int main()
{
    std::vector<int> a={4,2,2,2,4,4,2,2};
    std::vector<int> b={10,1,2,4,7,2};
    std::vector<int> c={8,2,4,7};
    std::vector<int> d={1,5,6,7,8,10,6,5,6};
    std::cout<<longestSubarray(a,0)<<"\n";
    std::cout<<longestSubarray(b,5)<<"\n";
    std::cout<<longestSubarray(c,4)<<"\n";
    std::cout<<longestSubarray(d,4)<<"\n";
    // std::cout<<longestSubarray(e,10)<<"\n";

}
