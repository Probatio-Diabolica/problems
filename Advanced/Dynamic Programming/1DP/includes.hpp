#include<iostream>
#include<vector>
#include<string>
#include<cstdint>
using namespace std;


typedef vector<int> iArray;

std::ostream& operator<<(std::ostream& stream,const std::vector<int>& vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" ";
    }
    return stream;
}