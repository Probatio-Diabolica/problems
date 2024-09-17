#include<iostream>
#include<unordered_map>

int main()
{
    std::unordered_map<int,int> map;

    int arrar[9]={1,2,2,2,2,2,2,3,4};
    ++arrar[7];
    ++arrar[7];
    ++arrar[7];
    ++arrar[7];
    for(int i=0;i<9;i++)
    {
        ++map[arrar[i]];
    }
    std::cout<<map[4];
}