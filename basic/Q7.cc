#include "includes.hpp"

std::vector<int> findUnion(std::vector < int > a, std::vector < int > b)
{
    std::vector<int> sol={};
    int i=0,j=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<=b[j])
        {
            if(sol.size()==0 || sol.back()!=a[i]) sol.push_back(a[i]);
            ++i;
        }
        else
        {
            if(sol.size()==0 || sol.back()!=b[j]) sol.push_back(b[j]);
            ++j;
        }
    }

    while(j<b.size())
    {
        if(sol.size()==0 || sol.back()!=b[j]) sol.push_back(b[j]);   
        ++j;
    }
    while(i<a.size())
    {
        if(sol.size()==0 || sol.back()!=a[i]) sol.push_back(a[i]);
            ++i;
    }
    return sol;
}



int main()
{
    std::vector<int> a={1,2,3,4,5};
    std::vector<int> b={2,3,4,6,7};
    std::cout<<findUnion(a,b);
}