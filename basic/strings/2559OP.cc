#include"include.hpp"


void prep(vector<int>& pSum,const  std::vector<string>& words)
{

    
}

std::vector<int> vowelStrings(const  std::vector<string>& words, const  vector<vector<int>>& queries) 
{
    int size=queries.size();
    std::vector<int> sol(size,0),pSum(size,0);
    unordered_map<char,int> map;
    map['a']=1;
    map['e']=1;
    map['i']=1;
    map['o']=1;
    map['u']=1;
    int temp=0;
    for(int i=0;i<words.size();i++)
    {
        temp+= ((map[words[i][0]] )  and (map[words[i][words[i].size()-1]])); 
        pSum[i]=temp; 
    }

    for(int i=0;i<queries.size();i++)
    {
        sol[i]=pSum[queries[i][1]] - ( (queries[i][0]==0) ? 0:pSum[queries[i][0]-1]);
    }
    return sol;

}

int main()
{
    std::cout<<"\n"<<vowelStrings({"a","e","i"},{{0,2},{0,1},{2,2}});
    std::cout<<"\n"<<vowelStrings({"aba","bcb","ece","aa","e"},{{0,2},{1,4},{1,1}});

}