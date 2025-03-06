#include "include.hpp"
// #include <string>


char findTheDifference(string s, string t) {
    vector<int> hash(26);
    for(int i=0;i<s.size();i++)
    {
        ++hash[t[i]-'a'];
        --hash[s[i]-'a'];
    }
    ++hash[t[t.length()-1]-'a'];
    char res='a';
    for(int i=0;i<26;i++)
    {
        if(hash[i]) res= 'a' + i;
    }
    return res;
}

int main()
{
    string s ="",t="j";
    std::cout<<findTheDifference(s, t);
}