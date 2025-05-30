#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;
typedef vector<int> iArray;
typedef unordered_map<int,int> iMap;

template<typename T>
ostream& operator <<(ostream& stream,vector<T> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" ";
    }
    stream<<"\n";
    return stream;
}

template<typename T>
ostream& operator <<(ostream& stream,const vector<T> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" ";
    }
    stream<<"\n";
    return stream;
}

#endif
