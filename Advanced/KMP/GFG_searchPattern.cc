// #include<string>
// #include<iostream>
// #include<vector>
#include"includes.hpp"



void computeLPS(std::string& pat,std::vector<int>& LPS,int m)
{
    int len=0;
    LPS[0]=0;

    int it=1;

    while(it < m)
    {
        if(pat[it] == pat[len])
        { 
            ++len;
            LPS[it]=len;
            ++it;
        } else{
            if(len != 0)
            {
                len = LPS[len-1];
            }else{
                LPS[it]=0;
                ++it;
            }
        }
    }   
}


std::vector<int> search(std::string& pat, std::string& txt) {
    int n=txt.length();
    int m=pat.length();

    std::vector<int> result;

    std::vector<int> LPS(m,0);

    computeLPS(pat,LPS,m);

    int i=0,j=0;
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            ++i;
            ++j;
        }
        if(j==m)
        {
            result.push_back(i-m);
            j=LPS[j-1];
        }
        else if( txt[i]!=pat[j])
        {
            if(j != 0) j=LPS[j-1];
            else ++i;
        }
    }

    return result;
}


int main()
{
    std::string wrd="aaaacaaa",pat="aa";
    cout<<search(pat,wrd);
}