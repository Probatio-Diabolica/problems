#include "include.hpp"

int con(std::string& str,int X, int Y)
{
    int sol=0;
    int x=X,y=Y;
    for(int i=0;i<x+y;i++)
    {
        if(i&1 and X>0)
        {
            str+="01";
            --X;
        }
        else if(Y>0)
        {
            str+="10";
            --Y;
        }
        else str+="01";
    }
    for(int i=0;i<str.length()-1;i++)
    {
        if(str[i]!=str[i+1]) ++sol;
    }
    return (x>y) ? sol-1 : sol;
}


int main()
{
    int T;
    int X, Y;

    std::cin>>T;
    while(T>0)
    {
        std::cin>>X>>Y;
        std::string s;
        s.reserve(X*Y*4);
        std::cout<<con(s,X,Y)<<'\n';
        --T;
    }
}