#include"includes.hpp"



int trap(std::vector<int>& height) {
    if (height.size()==0) return 0;
    int res=0;
    int l=0, r=height.size()-1,leftMax=height[0],rightMax=height[r];
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
        std::vector<int> hei={0};
        std::cout<<trap(hei);
}