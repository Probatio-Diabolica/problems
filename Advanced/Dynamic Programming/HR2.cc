#include"includes.hpp"

int max(int a, int b)
{
    return a > b ? a : b;
}

int max(int a, int b, int c)
{
    return max(max(a,b),max(b,c));
}

int poss(int begin , int end ,iArray& nums)
{
    int op1=0;
    int op2=0;
    for(int i = begin; i <= end ; ++i)
    {
        int curr = max(op1,op2+nums[i]);
        op2 = op1;
        op1=curr;
    }
    return op1;
}

int rob(iArray &nums)
{
    if(nums.size()==1) return nums[0];
    else if(nums.size()==2) return max(nums[0],nums[1]);
    else if(nums.size() ==3 ) return max(nums[0],nums[1],nums[2]);
    return max(poss(0,nums.size()-2,nums),poss(1,nums.size()-1,nums));
}

int main()
{
    iArray a={1, 2, 3, 4, 5, 1, 2, 3, 4, 5};   
    std::cout<<rob(a);
}