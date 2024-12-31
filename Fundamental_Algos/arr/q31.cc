#include"includes.hpp"
#include<algorithm>


static void swap(int& a,int & b)
{
    int temp=a;
    a=b;
    b=temp;
}


void nextPermutation(vector<int>& nums) {
    int size=nums.size();
    int pivot=-1;

    for(int i=size-1;i>-1;i--)
    {
        //note: we want to find that element which is smaller than its right, and it'll be our pivot
        //!! why?? bc:: we want to spot that smaller element as its existance means we can have another rotation possible without reversing the whole array
        if(nums[i]>nums[i-1])
        {
            pivot=i-1; //take the left item
            break;
        }
    }

    //if pivot is equals to -1, then it means we have to reverse the whole array
    // and it is only possible in case of [3,2,1] only 
    if(pivot!=-1)
    {
        int iswap=pivot;
        //if not then we'll look for the element which fom the right side, which is bigger than pivot element
        for(int j=size-1;j>=pivot;j--)
        {

            if(nums[pivot]<nums[j])
            {
                iswap =  j;
                break;
            }
        }
        //then swap these two
        swap(nums[pivot],nums[iswap]);
    }
    std::reverse(nums.begin()+pivot+1,nums.end());
}

int main()
{
    std::vector<int> a={1, 5, 8, 4, 7, 6, 5, 3, 1};
    nextPermutation(a);
    std::cout<<a;
}
