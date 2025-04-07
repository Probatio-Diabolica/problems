#include"includes.hpp"

void dfs(int node, vector<vector<int>> &adj,int vis[],vector<int>& ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for(int it: adj[node])
    {
        if(!vis[it]) dfs(it,adj,vis,ls);
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    // Code here
    int v = adj.size();
    int vis[v]={0};
    int start = 0;
    vector<int> ls;

    dfs(start,adj,vis,ls);

    return ls;
}

// int main()
// {
//     bMat gr={
//         {1,0,1,0,1},
//         {1,1,1,0,0},
//         {1,0,0,0,0},
//         {1,1,1,1,1},
//         {0,0,1,0,0}
//     };
//     int edges=0;
//     for(int row=0;row<gr.size();row++)
//     {
//         for(int col=0;col<gr.size();col++)
//         {
//             if(gr[row][col]) ++edges;
//         }
//     }

//     std::cout<<edges;
//     // std::cout<<DFS<int>(); //valid
// }