#include "includes.hpp"

int maxTurbulenceSize(std::vector<int>& arr) 
{
    if(arr.size()<2) return 1;
    int comp=0,left=0,right=0;
    int maxWin=0,SIZE=arr.size();
    while(++right < arr.size())
    {
        
        if(arr[right-1]  <  arr[right])
        {
            
            if(comp!=0) comp=0;
            else left=right-1;

        } 
        else if(arr[right-1]  >  arr[right])
        {
            if(comp!=-1) comp=-1;
            else left=right-1;
        }
        else
        {
            comp=404;
            left=right;
        }
        maxWin = (maxWin>(right-left+1)) ? maxWin : (right-left+1);
    }
    return maxWin;
}

int main()
{
    std::vector<int> a={9,4,2,10,7,8,8,1,9};
    std::vector<int> b={4,8,12,16};
    std::vector<int> c={2,4,2,5,0,1};
    std::vector<int> d={1,2,3,2,1};
    std::cout<<maxTurbulenceSize(a)<<"\n";
    std::cout<<maxTurbulenceSize(b)<<"\n";
    std::cout<<maxTurbulenceSize(c)<<"\n";
    std::cout<<maxTurbulenceSize(d)<<"\n";
}