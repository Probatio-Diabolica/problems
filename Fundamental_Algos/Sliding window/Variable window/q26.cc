#include"includes.hpp"

bool check_array(int arr[26],int arr2[26])
{
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=arr2[i]) return false;
    }
    return true;
}
bool checkInclusion(string s1,string s2) 
{
    if(s1.length()>s2.length()) return false;
    int mp1[26]={},mp2[26]={};

    int winLen=s1.length();
    for(int i=0;i<s1.length();i++)
    {
        ++mp1[s1[i]-'a'];
        ++mp2[s2[i]-'a'];
    }
    if(check_array(mp1,mp2)) return true;
    int left=0;
    for(int right=winLen;right<s2.length();right++)
    {

        ////decrease
        --mp2[s2[left]-'a'];

        ////increase
        ++mp2[s2[right] - 'a'];

        if(check_array(mp1,mp2)) return true;
        ++left;
        
    }
    return false;
}


bool checkInclusion2(string s1,string s2) 
{
    if(s1.length() > s2.length()) return false;
    int s1map[26]={},s2map[26]={};

    for(int i=0;i<s1.length();i++)
    {
        ++s1map[s1[i]-'a'];
        ++s2map[s2[i]-'a'];
    }
    bool result=false;
    int matches=0;
    for(int i =0;i<26;i++) matches+= (s1map[i]==s2map[i]);

    if(matches==26)  return true;
    
    int left=0;

    for(int r=s1.length();r<s2.length();r++)
    {

        int index= s2[r] - 'a';
        ++s2map[index];

        matches+= (s1map[index] == s2map[index]);
        matches-= ( s1map[index] +1 == s2map[index]);

        index=s2[left]-'a';
        --s2map[index];

        matches+=( s1map[index] == s2map[index] );
        matches-= ( s1map[index]-1 == s2map[index] ) ;
        ++left;

        if (matches==26)
        {
            result=true;
            return result;
        }
    }
    return result;
}


int main()
{
    string target="cbac",toFind="ccc";
    std::cout<<checkInclusion2(toFind,target);
}