#include"include.hpp"

// TC :: N(no. of neighbours) + 2E (twice of edges)
vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    
    int v =adj.size();
    
    std::vector<bool> vis(v,false);
    
    int s=0;
    
    vis[s]=true;
    
    queue<int> q;
    
    q.push(s);
    
    vector<int> bfs;
    


    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(int v : adj[node])
        {
            if(!vis[v]) 
            {
                vis[v]=true;
                q.push(v);
            }
        }
    }
    return bfs;
}


int main()
{
    iMat trust={{},{}};
}