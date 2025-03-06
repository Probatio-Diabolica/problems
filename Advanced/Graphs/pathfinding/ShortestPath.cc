#include "../includes.hpp"



void topoSort(int node,vector<vector<pair<int,int>>>&adj,vector<int> &viz,stack<int>& st)
{
    viz[node] = 1;
    for(auto it : adj[node])
    {
        int v= it.first;
        if(!viz[v]) topoSort(v, adj,viz, st);
    }
    st.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj;
    

    //make the distance
    for(int i=0;i<E;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    
    // Preparing the stack
    vector<int> viz(V,0);
    stack<int> st;
    for(int i=0;i<adj.size();i++)
    {
        if(!viz[i]) topoSort(i,adj,viz,st);
    }
    vector<int> dist(edges.size(),1e9);
    dist[0]=0;
    // calculate the distance
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        for(auto it: adj[node])
        {
            int v = it.first;
            int wt=it.second;
            if(dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}


int main()
{

}