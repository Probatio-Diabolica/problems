#include<iostream>
#include<vector>
#include<string>

using namespace std;


std::ostream& operator<<(std::ostream& stream,const std::vector<int>& vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" ";
    }
    return stream;
}