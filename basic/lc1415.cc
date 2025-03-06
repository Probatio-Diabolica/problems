#include"includes.hpp"

string getHappyString(int n, int k) 
{
    // auto cmp = [](std::string & a, std::string & b)
    // {
    //     for(int i = 0 ; i< a.length();i++)
    //     {
    //         if(a[i] < b[i]) return a;
    //         else if(a[i]>b[i]) return b; 
    //     }
    //     return a;
    // };
    // std::priority_queue<std::string,std::vector<string>,decltype(cmp(a, b))) heap;
    
    std::string temp;
    for(int i =0;i<n;i++)
    {
        if(i&1) temp+='b';
        else temp+='a';
    }
}


int main()
{
    std::cout<<getHappyString(1,3);
}