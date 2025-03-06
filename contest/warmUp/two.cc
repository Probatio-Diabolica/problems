#include<iostream>
#include<unordered_map>

int firstUniqChar(std::string s)
{
    std::unordered_map<char,int> map;
    for(int i =0;i<s.length();i++)
    {
        ++map[s[i]];
    }
    for(int i =0;i<s.length();i++)
    {
        if(map[s[i]]==1) return i;
    }
    return -1;        
}


int main()
{
    std::cout<<firstUniqChar("loveleetcode");
}