#include"includes.hpp"

int maxScore(std::string s) 
{
    int zero=0,result=0,one=0;
    for(auto i:s) if(i=='1') ++one;
    for(int i=0;i<s.length()-1;i++)
    {
        if (s[i]=='0')
        {
            ++zero;
        }else
        {
            --one;
        }
        if( (zero+one)>result) result=(zero+one);
    }
    return result;
}

int main()
{
    std::string a= "011101";
    std::cout<<maxScore(a);
}