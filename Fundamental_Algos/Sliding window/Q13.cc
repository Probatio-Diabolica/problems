#include<iostream>
#include<vector>

// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/
void switchNum(int &num)
{
    // if(num==1) num=0;
    // else num=1;
    num = (num==1) ? 0:1;
}
int minOperations(std::vector<int>& nums)
{
    int operations=0;
    for(size_t i =0;i<=nums.size()-3;i++)
    {
        if(nums[i]==0)
        {
            switchNum(nums[i]);
            switchNum(nums[i+1]);
            switchNum(nums[i+2]);
            operations++;
        }
        if ((i>0)and(nums[i-1])==0) return -1; 
    }
    if((nums[nums.size()-3+1]==0) || (nums[nums.size()-3+2]==0)) return -1;
    return operations;
}

int main()
{
    std::vector<int> a={0,1,1,1,0,0};
    std::vector<int> b={0,1,1,1};
    std::vector<int> c={1,1,1,0,0,1};
    std::vector<int> d={1,1,1,1,0,1};
    std::vector<int> e={0,0,0};
    std::cout<<minOperations(a)<<"\n";
    std::cout<<minOperations(b)<<"\n";
    std::cout<<minOperations(c)<<"\n";
    std::cout<<minOperations(d)<<"\n";
    std::cout<<minOperations(e)<<"\n";

}