#include"includes.hpp"



bool areAlmostEqual(string &s1, string &s2) {
    int map[26];
    int sol=0;
    for(int i=0;i<s1.length();i++)
    {
        ++map[s1[i] - 'a' ];
        ++map[s2[i] - 'a' ];
        if(s1[i]==s2[i]) ++sol;
    }

    if(sol == s1.length()) return true;

    for(int i =0;i<26;i++)
    {
        if(map[i]&1) return false; 
    }

    return sol == s1.length()-2 ? true : false;
}

int main()
{
    string a="kleb",b="kleb";
    std::cout<<areAlmostEqual(a,b);
}