#include "../includes.hpp"
#include <unordered_map>

using pVec = vector<pair<int,int>>;
vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    std::vector<int> result;
    result.reserve(query.size());


    //// source => {next | weight}
    std::unordered_map<int, pVec> adj;

    for(vector<int> &v : edges)
    {
        adj[v[0]].emplace_back(v[1],v[2]);
    }

    for(vector<int> &v : query)
    {
        int src = v[0];
        int dest = v[1];

        std::vector<bool> visited(n);
        visited[src]=true;


        //// pair => {distance , next}
        std::priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> minheap;
        
        for(pair<int,int> &node : adj[src])
        {
            minheap.push({node.second,node.first});
        }
        
        //// Dijkstra
        while(!minheap.empty())
        {
            pair<int,int> current= minheap.top();
            int next = current.second;
            int time = current.first;
            
            minheap.pop();

            if()

        }


        result.emplace_back();
    }
    return result;
}



int main()
{
    int n = 5; 
    iMat edges = {{0,1,7},{1,3,7},{1,2,1}}, query = {{0,3},{3,4}};

    std::cout<<minimumCost(n, edges, query);

}