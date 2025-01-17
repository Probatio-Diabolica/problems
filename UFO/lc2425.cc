#include"include.hpp"

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int res=0;

    if(nums2.size() & 1)
    {
        for(int i =0 ;i<nums1.size();i++)
        {
            res ^= nums1[i];
            // int temp=3456789;
        }
    }

    if(nums1.size() & 1)
    {
        for(int i =0 ;i<nums2.size();i++)
        {
            res ^= nums2[i];
        }
    }
    
    return res;
}


int main()
{
    iArray x={2,3,3,3,2},y={10,2,5,0};
    // iArray x = {2,1}, y={3,4};
    // iArray x={2,1,3},y={10,2,5,0};
    std::cout<<xorAllNums(x,y);
}