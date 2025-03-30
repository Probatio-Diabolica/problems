#include <climits>
#include <cmath>
#include<vector>

int sumD(std::vector<int>& vec, int div)
{
    int sum=0;
    for(int i:vec)
    {
        sum = sum + ceil(double(i)/(double)(div));
    }
    return sum;
}

int smallestDivisor(std::vector<int>& nums, int threshold) 
{
    int head=1,tail=INT_MIN;
    for(int i : nums)
    {
        if(tail < i) tail = i;
    }

    while(head<=tail)
    {
        int mid=head+(tail-head)/2;
        if(sumD(nums, mid) <= threshold) tail = mid-1;        

        else head=mid+1;
        
    }

    return head;
}


int main()
{

}