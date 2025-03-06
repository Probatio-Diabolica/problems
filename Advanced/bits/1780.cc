#include "includes.hpp"
#include <cmath>



int bs(int head, int tail, iArray& arr , int target)
{
    int mid = head+ (tail-head) /2;


    while(head<tail)
    {
        if(arr[mid] ==target)
        {
            return mid;
        }
        else if(arr[mid] >target)
        {
            tail = mid-1;
        }
        else
        {
            head = mid+1;
        }
        mid = head+ (tail-head) /2;
    }

    return mid;
}


bool powerOfThree(int n)
{
    iArray space(17);
    for(int i=0;i<17;i++)
    {
        space[i]=std::pow(3,i);
    }

    // std::cout<<space;
    // while(n>1)
    // {

    // }
    while(n>2)
    {
        n-=space[bs(0, 16, space, n)];
    }

    return (n>1) ? false : true;
}


int main()
{
    std::cout<<powerOfThree(21);
}