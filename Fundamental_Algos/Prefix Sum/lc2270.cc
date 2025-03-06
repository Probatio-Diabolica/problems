#include "includes.hpp"

int waysToSplitArray(const vector<int>& nums) 
{
    int solution=0;
    int size=nums.size();
    vector<int64_t> pSum(size);
    pSum[0]=nums[0];

    for(int i=1;i<size;i++) pSum[i]=pSum[i-1] + nums[i];

    for(int i=0;i<size-1;i++)
    {
        if(pSum[i] >= (pSum[size-1] - pSum[i])) ++solution;
    }

    return solution;
}


int main()
{
    std::cout<<"\n"<<waysToSplitArray({2,3,1,0});
    std::cout<<"\n"<<waysToSplitArray({10,4,-8,7});
    std::cout<<"\n"<<waysToSplitArray({84364, -32542, 95763, -67345, -92158, 78412, 60291, -34213, -13556, 46029, 48218, 92876, -84761, -18923, 75210, 23987, -53623, -21974, -53145, 88830, -8539, -46893, 15284, 23856, -9650, 68865, 32624, -84562, 14176, 22860, 26435, -23991});



}