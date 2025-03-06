#include "../includes.hpp"
#include <climits>
#include <vector>





// Algorithm
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    priority_queue<pair<int,int>,std::vector<pair<int,int>>,std::greater<std::pair<int,int>>> minHeap;
    std::vector<int> result(adj.size(),INT_MAX);

    result[src]=0;
    minHeap.push({0,src});

    while(!minHeap.empty())
    {
        int d=minHeap.top().first;
        int node=minHeap.top().second;
        minHeap.pop();

        for(auto& vec: adj[node])
        {
            int adjNode=vec.first;
            int weight=vec.second;

            if(d+weight < result[adjNode]) 
            {
                result[adjNode] = d+weight;
                minHeap.push({d+weight,adjNode});
            }
        }
    }

    return result;
}


// Dijkstra via set
vector<int> dijkstraSET(vector<vector<pair<int, int>>> &adj, int src)
{
    vector<int> result(adj.size(),INT_MAX);
    set<pair<int,int>> visiting;
    vector<pair<int,int>> visited;

    visiting.insert({0,src});
    result[src]=0;
    while(!visiting.empty())
    {
        auto &top=*visiting.begin();
        int dist = top.first;
        int node = top.second;

        visiting.erase(top);

        for(auto& vec:adj[node])
        {
            int nextNode = vec.first;
            int distance = vec.second;

            if(dist + distance < result[nextNode])
            {
                if(result[nextNode]!=INT_MAX) visiting.erase({result[nextNode],nextNode});

                result[nextNode] = dist + distance;
                visiting.insert({dist+distance,nextNode});
            }
        }

    }
    
    
    return result;
}




int main()
{
    std::vector<std::vector<std::pair<int,int>>> graph{{{0,1}},{{2,1}},{{1,0}}};
    std::cout<<dijkstra(graph, 0);
}