#include"includes.hpp"
#include <unordered_map>
#include <vector>

void dfs(int src,std::unordered_map<int, std::vector<int>>& adj,std::vector<bool>& visited,int &vertices,int &nodes)
{
    visited[src]=true;
    ++vertices;
    nodes += adj[src].size();
    for(int i : adj[src])
    {
        if(!visited[i]) dfs(i,adj,visited,vertices,nodes);
    }
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    int sol=0;
    std::unordered_map<int, std::vector<int>> map;
    std::vector<bool> visited(n);
    for(int  i = 0;i<edges.size();i++)
    {
        
        map[edges[i][0]].emplace_back(edges[i][1]);
        map[edges[i][1]].emplace_back(edges[i][0]);
        
    }

    //traversing the graph
    for(int src =0;src<n;src++)
    {
        if(!visited[src])
        {
            int v = 0 , e=0;

            dfs(src,map,visited,v,e);

            if((v *(v-1))==e)    ++sol;
            
        }
    }

    return sol;
}



int main()
{
    iMat g={{2,1}};
    std::cout<<countCompleteComponents(3, g);
}