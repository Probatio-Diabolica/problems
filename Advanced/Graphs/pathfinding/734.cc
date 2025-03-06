#include "../includes.hpp"
#include <climits>
#include <functional>
#include <queue>

#include <unordered_map>
#include <utility>
#include <vector>


int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    priority_queue<pair<int,int>, vector<pair<int,int>>,std::greater<pair<int,int>>> minHeap;
    std::vector<int> visited(n+1,INT_MAX);
    visited[0] = 0;
    visited[k] = 0;

    unordered_map<int,vector<pair<int,int>>> adj;
    for(auto node: times)
    {
        int s = node[0];
        int t = node[1];
        int time = node[2];

        adj[s].push_back({t, time});
    }

    minHeap.push({k,0});


    while(!minHeap.empty())
    {
        int curDist = minHeap.top().second;
        int node    = minHeap.top().first;
        minHeap.pop();

        for(auto& nextNode: adj[node])
        {
            int newDist = nextNode.second;
            int newNode = nextNode.first;
            // if the node result is smaller than the previous visited value, update it with node value
            if(newDist+curDist < visited[newNode])
            {
                visited[newNode] = newDist + curDist;
                minHeap.push({newNode,newDist + curDist});
            }
        }
        
    }

    int sol = -1;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==INT_MAX) return -1;
        sol = (sol > visited[i]) ? sol : visited[i];
    }
    return sol;
}

int main()
{
    iMat graph = {
        {1,2,1},
        {2,5,1},
        {2,3,1},
        {3,4,1},
        {4,6,1},
    };

    std::cout<<networkDelayTime(graph, 6, 1);
}