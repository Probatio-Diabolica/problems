#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;
typedef vector<int> iArray;
ostream& operator <<(ostream& stream,vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" ";
    }
    stream<<"\n";
    return stream;
}

#endif
