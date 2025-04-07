#include"../includes.hpp"
#include <climits>
#include <unordered_map>


vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    vector<int> result(adj.size(),INT_MAX);
    result[src] = 0;
    
    unordered_map<int, vector<pair<int,int>>> map;
    
    for(int i=0;i<adj.size();i++)
    {
        for(pair<int,int> &p:adj[i])
        {
            // {  code , next  }
            map[i].push_back({p.second,p.first});
        }
    }
    // structure { 1 -> cost , 2-> node}
    priority_queue<pair<int,int>,vector<pair<int,int>>,std::greater<pair<int,int>>> min_heap;
    min_heap.push({0,src});
    
    while(!min_heap.empty())
    {
        pair<int,int> current= min_heap.top();
        int nextNode = current.second;
        int cost = current.first;
        min_heap.pop();
        for(pair<int,int>& node : map[nextNode])
        {
            int newCost = cost + node.first;
            int dest = node.second;
            if(result[dest] > newCost)
            {
                result[dest] = newCost;
                min_heap.push({newCost , dest});
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