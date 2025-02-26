#include"includes.hpp"

// bfs works
// bool isCyclic(std::vector<std::vector<int>>& adjList,std::vector<bool>& visited,std::vector<bool>& tempVisit, int currentNode)
// {   
//     visited[currentNode] = true;
//     tempVisit[currentNode] = true;
//     for(int& nextNode:adjList[currentNode])
//     {
//         if((!visited[nextNode]) and (isCyclic(adjList, visited, tempVisit, nextNode))) return true;
//         else if (tempVisit[nextNode]) return true;
//     }
//     tempVisit[currentNode]=false;
//     return false;
// }

// vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//     std::vector<int> sol;
//     std::vector<bool> visited(graph.size(),false),dfsVis(graph.size(),false);
//     sol.reserve(graph.size());
//     for(int i=0;i<graph.size();i++)
//     {
//         if(!visited[i]) isCyclic(graph,visited,dfsVis,i);
//     }

//     for(int i =0;i<dfsVis.size();i++)
//     {
//         if(!dfsVis[i]) sol.push_back(i);
//     }
//     return sol;
// }

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    std::vector<int> sol;
    sol.reserve(graph.size());
    std::vector<int> degree(graph.size(),0);
    std::unordered_map<int, vector<int>> map;
    std::queue<int> q;

    for(int i=0;i<graph.size();i++)
    {
        for(int node:graph[i])
        {
            map[node].push_back(i);
            ++degree[i];
        }
    }
    for(int i=0;i<degree.size();i++)
    {
        if(!degree[i]) q.push(i);
    }
    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for(int i:map[currentNode])
        {
            --degree[i];
            if(!degree[i]) q.push(i);
        }

    }

    for(int i=0;i<degree.size();i++)
    {
        if(!degree[i]) sol.push_back(i);
    }
    return sol;
}


int main()
{
    iMat graph={{1,2},{2,3},{5},{0},{5},{},{}};
    std::cout<<eventualSafeNodes(graph);

}