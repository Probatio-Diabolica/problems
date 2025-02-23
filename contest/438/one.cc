#include<bits/stdc++.h>
using std::string;


void reverse(string& s)
{
    for(int i=0;i<s.length()/2;i++)
    {
        char temp=s[i];
        s[i]=s[s.length()-1 -i];
        s[s.length()-1 -i]=temp;
    }
}

bool hasSameDigits(string s) {
    while(s.length()>2)
    {
        for(int i=0;i<s.length()-1;i++)
        {
            int a=s[i]-'0';
            int b=s[i+1]-'0';
            s[i]='0'+((a+b)%10);
        }
        s.pop_back();
    }
    return s[0]==s[1];
}

int main()
{
    std::cout<<hasSameDigits("323")<<'\n';
    std::cout<<hasSameDigits("3902")<<'\n';
    std::cout<<hasSameDigits("34789");
}