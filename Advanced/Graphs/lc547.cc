#include"includes.hpp"


void dfs(int node,vector<vector<int>>& graph,vector<bool>& visited)
{
    visited[node]=1;
    for(int i = 0;i < graph.size();i++)
    {
        if(graph[node][i] && !visited[i]) dfs(i,graph,visited);
    }
}



int findCircleNum(vector<vector<int>>& isConnected) {
    int vertices = isConnected.size();
    int connected= 0;
    vector<bool> visited(vertices);

    for(int i =0;i<vertices;i++)
    {
        if(!visited[i])
        {
            ++connected;
            dfs(i,isConnected,visited);
        }
    }
    return connected;
}


int main()
{

}