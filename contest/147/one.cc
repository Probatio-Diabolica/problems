// #include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool hasMatch(string s, string p) 
{
    if(p[p.length()-1]=='*') 
    {
        p=p.substr(0,p.length()-1);
    }
    for(int l=0,r=0,i=0;i<s.length();i++)
    {
        if(p[r]=='*') 
        {
            l=r+1;
            r=l;
            i--;
        }else if(p[r]==s[i]) ++r;
        else  {
            i-=(r-l);
            r=l;
        }
        if(r>=p.length()) return true;
    }

    return false;
}

int main()
{
    cout<<"\n"<<hasMatch("leetcode","ee*e");
    cout<<"\n"<<hasMatch("car","a*");
    cout<<"\n"<<hasMatch("kjbs","s*");
    cout<<"\n"<<hasMatch("wwmwww","wm*");
    cout<<"\n"<<hasMatch("mqmmmqmqbmqq","mmqm*b");

}