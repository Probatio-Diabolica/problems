#include"includes.hpp"

// https://leetcode.com/problems/minimum-window-substring/


std::string minWindow(std::string s,std::string t)
{
    std::vector<int> hashmap(256, 0);
    int L=0,R=0, minlen=INT_MAX, start=-1, cnt=0;
    // if(s==t) return s;
    for(int i=0;i<t.size();i++)
    {
        ++hashmap[t[i]];
    }

    while(R<s.size())
    {
        if(hashmap[s[R]]>0) cnt++;
        --hashmap[s[R]];
        
        while(cnt==t.size())
        {
            if(R-L+1 < minlen)
                {
                    minlen = R-L+1;
                    start = L;
                }
            ++hashmap[s[L]];
            
            if(hashmap[s[L++]]>0)--cnt;
        }
        ++R;
    }
    return start==-1? "":s.substr(start, minlen);
}


int main()
{
    std::string tar="a";
    std::string pat="a";

    std::cout<<minWindow(tar,pat);

}