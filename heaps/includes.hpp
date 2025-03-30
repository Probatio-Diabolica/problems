#ifndef INCLUDE_HPP
#define INCLUDE_HPP
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include <algorithm>

using namespace std;
using minHeap = std::priority_queue<int,std::vector<int>,std::greater<int>>;
using maxHeap = std::priority_queue<int>;
typedef vector<int> iArray;

using iMat = std::vector<std::vector<int>>;

typedef unordered_map<int,int> iMap;
template<typename t>
ostream& operator <<(ostream& stream,vector<t> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" ";
    }
    stream<<"\n";
    return stream;
}

template<typename t>
ostream& operator <<(ostream& stream,const vector<t> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" ";
    }
    stream<<"\n";
    return stream;
}

#endif
