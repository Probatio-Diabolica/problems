#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include<iostream>

#include<vector>

#include<unordered_map>


using  std::vector,std::unordered_map,std::ostream;

using iArray     = vector<int>                ;
using bArray     = vector<bool>               ;
using iMat       = vector<iArray>             ;
using bMat       = vector<bArray>             ;
using iMap       = unordered_map<int,int>     ;
using iLisGraph  = unordered_map<int,iArray>  ;


template<typename type>
ostream& operator <<(ostream& stream,vector<type> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<" "<<vec[i];
    }
    stream<<"\n";
    return stream;
}

template<typename type>
ostream& operator <<(ostream& stream,const vector<type> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<" "<<vec[i];
    }
    stream<<"\n";
    return stream;
}

#endif
