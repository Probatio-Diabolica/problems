#include"include.hpp"



bool hasSpecialSubstring(string s, int k) 
{
    if(s.length()==1) return true;
    bool sol=false;
    int l=0,r=0;
    // --k;
    while(r<s.length())
    {
        // char ls=s[l],rs=s[r];
        if((r-l) <= k-1)
        {
            if(s[l] != s[r])
            {
                l=r;
                ++r;
                std::cout<<l<<'\n';
            }else
            {
                ++r;
            }
        }
        if((r-l) >= k)
        {
            int checker=0;
            if((l-1)>-1)
            {
                ++checker;
                if(s[l-1]!=s[l]) --checker;
            }
            if((r+1)<s.length())
            {
                ++checker;
                if(s[r]!=s[r+1]) --checker;
            }
            if(checker==0) return true;
        }
        // ++r;
    }
    return sol;
}

int main()
{
    string s="aabcd";
    std::cout<<hasSpecialSubstring(s,2);
}