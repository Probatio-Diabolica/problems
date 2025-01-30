#include"include.hpp"


int removeDuplicates(vector<int>& nums) 
{

    int x=1,y=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[y]!=nums[i])
        {
            nums[x]=nums[i];
            ++x;
            y=i;
        }
    }
    return x;
}

int main()
{
    std::vector<int> a={0,0,1,1,1,2,2,3,3,4};
    std::cout<<removeDuplicates(a)<<"\n";
    std::cout<<a;
}