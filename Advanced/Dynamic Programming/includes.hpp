#include<iostream>
#include<vector>
#include<string>
#include<cstdint>
using namespace std;


using bArray = std::vector<bool>;
typedef vector<int> iArray;


template<typename type>
std::ostream& operator<<(std::ostream& stream,const std::vector<type>& vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<" "<<vec[i];
    }
    std::cout<<'\n';
    return stream;
}