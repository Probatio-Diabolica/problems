#include"includes.hpp"


void swap(int &a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}

vector<int> pivotArray(vector<int>& nums, int pivot) {
    std::vector<int> sol(nums.size(),pivot);
    int curr=0,sw=0,piv=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<pivot)
        {
            sol[curr++]=nums[i];
        }else if(nums[i]>pivot)
        {
            swap(nums[sw],nums[i]);
            ++sw;
        }else
        {
            ++piv;
        }
    }
    
    curr +=piv;
    for(int i=0;i<sw;i++)
    {
        sol[curr++]=nums[i];
    }

    return sol;
}


int main()
{
    iArray x ={9,12,5,10,14,3,10};
    std::cout<<pivotArray(x, 10);
}