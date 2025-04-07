#include "includes.hpp"

int maxActiveSectionsAfterTrade(string &s) {
    int sol=0;
    int l =0, r=0 , maxZeros=0;
    s = '1' + s + '1';

    for(int i =0;i<s.length();i++)
    {
        if(s[i]=='1') 
        {
            if(l>0 and r>0) maxZeros=std::max(maxZeros , l+r);                
            l=r;
            r=0;
            ++sol;
            // int temp=0;
        }
        else if(s[i]=='0' or  (i>0 and s[i]==s[i-1]) )++r;
        // int wut=0;
    }

    return sol + maxZeros -2;    
}


int main()
{
    std::string s="10110";
    std::cout<<maxActiveSectionsAfterTrade(s);


}