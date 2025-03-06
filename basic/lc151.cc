
#include "includes.hpp"

string reverseWords(const string &s) {
    string solution;
    vector<string> sep;
    int r=0,l=0;
    for(int temp=0;temp<s.length();temp++)
    {
        if(s[temp] == ' ')
        {
            r=temp+1;
            l=temp+1;
        }else
        {
            r=temp;
            l=temp;
            temp=s.length();
        }

    }
    for(;r<s.length();r++)
    {
        if(s[r] == ' ')
        {
            string x=s.substr(l,r-l);
            if(x!="")             sep.push_back(x);
            l=r+1;
        }
    }
    sep.push_back(s.substr(l,r-l));
    for(int i =sep.size()-1;i>-1;i--)
    {
        
        if(sep[i]!="")
        {
            solution+=sep[i];
            if(i>0) solution+=" ";
        }
    }
    return solution;
}

int main()
{
    cout<<reverseWords("the cat rolled over the car");
}