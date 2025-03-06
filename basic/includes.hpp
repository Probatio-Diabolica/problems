#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<climits>
#include<deque>
#include<set>
#include<queue>
using namespace std;
std::ostream& operator<<(std::ostream &stream, std::vector<int> &vec)
{
    for(size_t i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" , ";
    }
    return stream;
}
std::ostream& operator<<(std::ostream &stream, std::vector<int> vec)
{
    for(size_t i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" , ";
    }
    return stream;
}
