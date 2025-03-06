#include"include.hpp"

typedef vector<string> sArray;
bool check( string& real, string& sub)
{
    int subIT=0;
    
    for(int i =0;i<=(real.length()-(sub.length()-subIT));i++)
    {
        if(real[i]==sub[subIT]) ++subIT;
        else
        {
            i=(i-subIT);
            subIT = 0;
        } 
        if(subIT >=sub.length()) return true;
    }
    return false;
}



vector<string> stringMatching(vector<string>& words)
{
    sArray sol={};

    sort(words.begin(),words.end(),[](string &a,string& b )
    {
        return a.length() < b.length();
    });
    
    for(int i=0;i<words.size()-1;i++)
    {
        for(int j=i+1;j<words.size();j++)
        {
            if((words[i].size() != words[j].size()) and check(words[j],words[i])) 
            {
                
                sol.push_back(words[i]);
                ++i;
                j=i;
            }
        }
    }

    return sol;
}



int main()
{
    sArray words={"leetcode","code" ,"ode","eet"},words2={"eeeet","eeet"};
    cout<<stringMatching(words2);
    std::cout<<stringMatching(words);
    // std::cout<<check(words[0],words[2]);
}