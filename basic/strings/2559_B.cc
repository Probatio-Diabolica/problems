#include"include.hpp"


bool vowelsOrNot(std::string & str,unordered_map<char,int>& mp)
{
    int n= str.size()-1;
    return (( mp[str[0]])and (mp[str[n]]));
}


int check(int head,int tail,std::vector<string>& words,unordered_map<char,int>& mp)
{
    int sol=0;
    for(int i=head;i<tail;i++)
    {
        sol+=vowelsOrNot(words[i],mp);
    }
    return sol;
}

std::vector<int> vowelStrings( std::vector<string>& words,  vector<vector<int>>& queries) 
{
    
    unordered_map<char,int> map;
    map['a']=1;
    map['e']=1;
    map['i']=1;
    map['o']=1;
    map['u']=1;
    int size=queries.size();
    std::vector<int> sol(size,0);
    for(int i =0;i<size;i++)
    {
        sol[i]=check(queries[i][0],queries[i][1]+1,words,map);
    }
    return sol;
}

int main()
{
    std::vector<std::string> a={"aba","bcb","ece","aa","e"};
    std::vector<std::vector<int>> b={{0,2},{1,4},{1,1}};
    std::cout<<vowelStrings(a,b);
    // std::cout<<"\n"<<vowelStrings({"a","e","i"},{{0,2},{0,1},{2,2}});
    
}