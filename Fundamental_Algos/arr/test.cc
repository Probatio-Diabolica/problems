#include"includes.hpp"



int missingNum(std::vector<int>& vec)
{
    int sum=0;
    for(int i=0;i<vec.size();i++)
    {
        sum+=((i+1) - vec[i]);
    }
    return sum;
}


int main()
{
    std::vector<int> a{0,1,2,3};
    std::cout<<missingNum(a);
}