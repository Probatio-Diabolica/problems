#include"include.hpp"


int trap(const std::vector<int>& height)
{
    if (height.size()==0) return 0;
    int res=0,l=0, r=height.size()-1;
    int leftMax=height[0],rightMax=height[r];
    while(l<r)
    {
        if(leftMax<rightMax)
        {
            ++l;
            if(height[l]>leftMax) leftMax=height[l];
            res+=leftMax-height[l];
        }else
        {
            --r;
            if(rightMax<height[r]) rightMax=height[r];
            res+=rightMax-height[r];
        }
    }
    return res;
}


int main()
{
    cout<<trap({0,1,0,2,1,0,1,3,2,1,2,1});
}