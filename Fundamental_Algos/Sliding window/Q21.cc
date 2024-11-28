#include "includes.hpp"
// https://leetcode.com/problems/replace-the-substring-for-balanced-string/?envType=problem-list-v2&envId=sliding-window
int balancedString(std::string s) 
{
    int q=0,w=0,e=0,r=0,cap=s.length()/4,output=0;
    for(size_t right=0;right<s.length();right++)
    {
        switch (s[right])
        {
        case 'Q':
            ++q;
            break;
        case 'W':
            ++w;
            break;
        case 'E':
            ++e;
            break;
        case 'R':
            ++r;
            break;
        }
    }
    if(q>cap) output+=q-cap;
    if(w>cap) output+=w-cap;
    if(e>cap) output+=e-cap;
    if(r>cap) output+=r-cap;
    std::cout<<q<<" "<<w<<" "<<e << " "<<r<<"\n";
    return output;
}

int main()
{
    std::string a="QWER";
    std::string b="QQQW";
    std::string c="WWEQERQWQWWRWWERQWEQ";
    // std::cout<<balancedString(a)<<"\n";
    // std::cout<<balancedString(b)<<"\n";
    std::cout<<balancedString(c);
}



