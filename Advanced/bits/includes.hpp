#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <climits>
#include <functional>
#include<iostream>

#include<vector>

#include<unordered_map>

#include<queue>

#include<unordered_set>

#include<set>

#include<stack>

#include <cstdint>



using  std::set,std::pair,std::priority_queue,std::vector,std::unordered_map,std::ostream,std::queue,std::string,std::unordered_set,std::stack;

using iArray     = vector<int>                ;
using bArray     = vector<bool>               ;
using iMat       = vector<iArray>             ;
using bMat       = vector<bArray>             ;
using iMap       = unordered_map<int,int>     ;
using iLisGraph  = unordered_map<int,iArray>  ;


template<typename type,typename type2>
ostream& operator <<(ostream& stream,std::pair<type,type2>& pair)
{
    stream<<pair.first<<" | "<<pair.second<<'\n';
    return stream;
}

template<typename type>
ostream& operator <<(ostream& stream,std::pair<type,type>& pair)
{
    stream<<pair.first<<" | "<<pair.second<<'\n';
    return stream;
}

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
