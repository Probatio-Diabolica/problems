#include<iostream>
#include<vector>
#include<string>
#include<cstdint>
#include<cstring>
using namespace std;


using iArray= vector<int>;

std::ostream& operator<<(std::ostream& stream,const iArray& vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" ";
    }
    return stream;
}