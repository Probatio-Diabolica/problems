#include <algorithm>
#include<iostream>
#include <vector>

bool fitPossible(std::vector<int>& barn,int cows,int fit)
{
    int ins=1;
    int last=barn[0];
    for(int i=1;i<barn.size();i++)
    {
        if(fit <= (barn[i] - last) )
        {
            last=barn[i];
            ++ins;
        }
    }
    return (ins < cows) ?  false : true  ;
}

int minDistance(std::vector<int>& barn,int cows)
{
    std::sort(barn.begin(),barn.end());
    int left=1,right=barn[barn.size()-1]-barn[0];
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(fitPossible(barn, cows, mid))
        {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return right;
}


int main()
{
    int t;
    std::cin>>t;
    while((--t)> -1)
    {
        int n , cows;
        std::cin>>n>>cows;
        std::vector<int> barn(n);
        for(int i=0;i<n;i++)
        {
            std::cin>>barn[i];
        }
        std::cout<<minDistance(barn, cows);
    }
}