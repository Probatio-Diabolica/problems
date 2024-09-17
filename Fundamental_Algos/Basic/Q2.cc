#include<iostream>
#include<vector>

std::vector<int> rearrangeArray(std::vector<int>& nums) 
{
    //!! optimizations
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);  
    // 

    int nI=1,pI=0;
    std::vector<int> a(nums.size(),0);
    for(size_t i=0;i<nums.size();i++)
    {
        if(nums[i]>0) 
        {
            a[pI]=nums[i];
            pI+=2;
        }else
        {
            a[nI]=nums[i];
            nI+=2;
        }
    }
    return a;
}

std::ostream& operator<<(std::ostream& stream, std::vector<int> nums)
{
    for(size_t i=0;i<nums.size();i++)
    {
        stream<<nums[i]<<" , ";
    }
    return stream;
}

int main()
{
 std::vector<int> a={3,1,-2,-5,2,-4};
    std::cout<<rearrangeArray(a);
}