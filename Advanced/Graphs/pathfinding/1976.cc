#include "../includes.hpp"
#include <climits>
#include <queue>


using src  = int;
using dest = int;
using cost = long long;

int countPaths(int n, vector<vector<int>>& roads) {
    int m = 1e9+7;
    std::unordered_map<src,vector<std::pair<dest,cost>>> mp;
    std::vector<cost> minimumCost(n,LONG_LONG_MAX);
    std::vector<int> ways(n);
    for(vector<int> &v:roads)
    {
        mp[v[0]].emplace_back(v[1],v[2]);
        mp[v[1]].emplace_back(v[0],v[2]);
    }
    std::priority_queue<std::pair<cost,dest>,std::vector<std::pair<cost,dest>>, std::greater<std::pair<cost,dest>> > Q;
    Q.push({0,0});
    minimumCost[0]=1;
    ways[0]=1;
    while(!Q.empty())
    {
        cost time = Q.top().first;
        dest now = Q.top().second;
        Q.pop();

        for(auto &p:mp[now])
        {
            int ngbr = p.first;
            int tyme = p.second;

            if(time + tyme < minimumCost[ngbr])
            {
                minimumCost[ngbr] = time + tyme;
                Q.push({minimumCost[ngbr],ngbr});
                ways[ngbr]=ways[now];
            }else if(time + tyme == minimumCost[ngbr]) ways[ngbr]=(ways[ngbr]+ways[now])%m;
            
        }
    }
    return ways[n-1];
}

int main()
{

}