#include "includes.hpp"

int maxVowels(std::string s, int k)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int nums=0,maxN=0;
    for(int i=0;i<k and i<s.size();i++) if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u') ++nums;
    maxN=nums;
    for(int i=1;i<=s.length()-k;i++)
    {
        int current=i+k-1;
        if(s[i-1]=='a' or s[i-1]=='e' or s[i-1]=='i' or s[i-1]=='o' or s[i-1]=='u') --nums;
        if(s[current]=='a' or s[current]=='e' or s[current]=='i' or s[current]=='o' or s[current]=='u') ++nums;
        maxN=maxN>nums? maxN:nums;
    }
    return maxN;
}

int main()
{
    std::pair<std::string,int> a={"abciiidef",3};
    std::pair<std::string,int> b={"ibpbhixfiouhdljnjfflpapptrxgcomvnb",33};
    std::pair<std::string,int> c={"aeiou",2};
    std::pair<std::string,int> d={"leetcode",3};
    std::cout<<maxVowels(a.first,a.second)<<"\n";
    std::cout<<maxVowels(b.first,b.second)<<"\n";
    std::cout<<maxVowels(c.first,c.second)<<"\n";
    std::cout<<maxVowels(d.first,d.second)<<"\n";
}