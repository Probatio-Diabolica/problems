#include<fstream>
#include<iostream>
#include<vector>
#include<unordered_map>
#include <sstream>
#include <string>


typedef std::unordered_map<int,int> map;
typedef std::vector<int> Arr;
typedef std::vector<Arr> tArr; 


std::ostream &operator<<(std::ostream& stream, Arr& vec)
{
    for(int i=0;i<vec.size();i++)
    {
        stream<<vec[i]<<" , ";
    }
    stream<<"\n";
    return stream;
}

std::ostream &operator<<(std::ostream& stream,std::vector<Arr> & arr)
{
    for(int i=0;i<arr.size();i++)
    {
        stream<<arr[i]<<"\n";
    }
    return stream;
}