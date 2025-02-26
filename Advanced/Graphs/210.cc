#include"includes.hpp"


vector<int> topologicalSort(unordered_map<int,vector<int>>&adj,int n,vector<int>& indegree)
{
    queue<int> q;
    vector<int> result;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            result.push_back(i);
            ++count;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int& visited : adj[node])
        {
            --indegree[visited];
            if(indegree[visited]==0)
            {
                result.push_back(visited);
                ++count;
                q.push(visited);
            }
        }
    }
    if(count==n) return result;
    return {};
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int ,vector<int>>adj;
    vector<int> indegree(numCourses,0);
    for(auto& vec:prerequisites)
    {
        int a=vec[0];
        int b=vec[1];

        adj[b].push_back(a);
        ++indegree[a];
    }

    return topologicalSort(adj,numCourses,indegree);
}


int main()
{
    std::vector<std::vector<int>> pre={{1,0}};
    std::cout<<findOrder(2,pre);
}