#include"includes.hpp"




typedef vector<int> iArray;

iArray memoArr(int(1e5),-1);

int minimum(int a,int b)
{
    return (a > b) ? b : a;
}

int jump(iArray& heights,int choices,int position)
{
    if(position > heights.size()-1) return 0;
    if(memoArr[position] !=-1) return memoArr[position];
    int cost =INT32_MAX;
    for(int i=1;i<=choices;i++)
    {
        if((position+i) < heights.size()) cost = minimum(cost , jump(heights,choices,position+i) + std::abs(heights[position]-heights[position+i]));
        else if(cost==INT32_MAX) cost =0;
    }

    return memoArr[position]= cost;
}


int main()
{
    int n,k;
    std::cin>>n>>k;
    iArray heights(n);
    for(int i = 0;i<n;i++)
    {
        std::cin>>heights[i];
    }
    std::cout<<jump(heights,k,0);
}