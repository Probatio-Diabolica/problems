#include "includes.hpp"



void DFS(vector<int>& nodes, int init, vector<bool>& visited,stack<int>& st)
{
    visited[init] = true;
    for(int &node: nodes)
    {
        if(!visited[node])
        {
            DFS(nodes,node,visited,st);
        }
    }

    st.push(init);
}


// toposort using DFS
vector<int> topologicalSort(vector<vector<int>>& adj) {
    bArray visited(adj.size(),false);
    std::stack<int> st;

    for(int i=0;i<adj.size();i++)
    {
        if(!visited[i])
        {
            DFS(adj[i],i,visited,st);
        }
    }

    iArray sol(st.size(),0);
    int i=0;
    while(!st.empty())
    {
        sol[i++]=st.top();
        st.pop();
    }

    return sol;
}


int main()
{
    iMat adj={{},{0},{0},{0}};
    std::cout<<topologicalSort(adj);
}