#include <iostream>

int sol(std::string& str)
{
    int solu=0,temp=0;
    for(int l=0,r=0;r<str.length();r++)
    {
        
        if(str[l]==str[r])
        {
            ++temp;
        }else
        {
            temp=1;
            l=r;
        }
        
        solu= solu > temp ? solu : temp;
    }
    return solu;
}

int main()
{
    std::string s;
    std::cin>>s;

    std::cout<<sol(s);
    
}