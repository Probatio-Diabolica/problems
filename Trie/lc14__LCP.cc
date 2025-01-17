#include<iostream>
#include<vector>
#include<string>
using std::string, std::vector;

std::ostream& operator<<(std::ostream & stream, const vector<string>& vec)
{
    for(int i =0;i<vec.size();i++)
    {
        stream<<vec[i]<<"\n";
    }
    return stream;
}

void calculatePrefix(string& a, string& b, int & tail)
{
    int head=0;
    while(head<tail)
    {
        if(a[head]!=b[head])
        {
            tail=head;
            return;
        }
        ++head;
    }
}


string longestCommonPrefix(vector<string>& strs) 
{
    if(strs.size()==1) return strs[0];
    string longest="";
    int lim=strs[0].size();
    if(lim==0) return "";
    for(int i=1;i<strs.size();i++)
    {
        string &prev=strs[i-1];
        string & now=strs[i];
        if(now.length()==0) return "";
        if(now.size()<lim) lim=now.size();
        calculatePrefix(prev,now,lim);
        if(lim==-1) return longest;
    }
    if(lim>0)
    {
        std::cout<<lim;
        longest=strs[0].substr(0,lim);
    }
    return longest;
}

int main()
{
    vector<string> a={"ab","a"},b={"flower","flow","flight"};
    std::cout<< longestCommonPrefix(a) ;
}