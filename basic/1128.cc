// #include<iostream>
#include <algorithm>
#include <map>
#include<vector>
using namespace std;
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int sol = 0;
    map<vector<int>,int> mp;
    sort(dominoes.begin(),dominoes.end());
    for(int i =0;i<dominoes.size();++i)
    {
        ++mp[dominoes[i]];
    }

    for(int i=0;i<dominoes.size()-1;++i)
    {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        sol+= mp[{a,b}] -1;
        --mp[{a,b}];
        if(b>a) sol+= mp[{b,a}];
    }
    return sol;
}

int main()
{

}