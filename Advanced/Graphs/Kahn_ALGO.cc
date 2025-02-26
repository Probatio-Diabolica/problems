#include"includes.hpp"

vector<int> topologicalSort(vector<vector<int>>& adj) {
    iArray res(adj.size()),inDegree(adj.size());
    std::queue<int> q;
    for(int i=0;i<adj.size();i++)
    {
        for(int a:adj[i])
        {
            ++inDegree[a];
        }
    }
    int place=0;
    for(int i=0;i<inDegree.size();i++)
    {
        if(!inDegree[i])
        {
            q.push(i);
        }
    }


    while(!q.empty())
    {
        int currentNode=q.front();
        q.pop();
        res[place++]=currentNode;
        for(int i: adj[currentNode])
        {
            --inDegree[i];
            if(!inDegree[i])
            {
                q.push(i);
            }
        }
    }
    return res;
}

int main()
{
    iMat adj={{},{0},{0},{0}};
    std::cout<<topologicalSort(adj);
}