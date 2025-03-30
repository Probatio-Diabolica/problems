#include<iostream>
#include <vector>


int bsneg(int head, int tail , std::vector<int> & nums)
{

}

int bsPos(int head, int tail , std::vector<int> & nums)
{

}

int maximumCount(std::vector<int> & nums) 
{
    //search for zero
    int head = 0, tail = nums.size()-1;
    int mid = head + (tail-head) /2, zero=0;
    while(head<=tail)
    {
        if(nums[mid]==0)
        {
            zero =0;
        }
        else if(nums[mid] >1)
        {
            
        }
    }
    return             
}

int main()
{

}