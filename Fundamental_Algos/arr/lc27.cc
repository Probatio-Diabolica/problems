#include"includes.hpp"

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int removeElement(vector<int>& nums, int val) {
    int k=0;
    int l=0,r=0;
    for(;l<nums.size();l++)
    {
        if(nums[l]!=val)
        {
            swap(nums[l],nums[r]);
            ++r;
            ++k;
        }
    }

    return k;
}

int main()
{
    std::vector<int> a={1,2,2,3,5,6};
    std::cout<<removeElement(a,2)<<"\n";
    std::cout<<a;
}