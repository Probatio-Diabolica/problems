#include"../includes.hpp"
#include <climits>


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
    std::vector<int> visited(n,INT_MAX);
    visited[src] = 0;
    vector<vector<pair<int,int>>> adj;
    
    for(int i = 0;i<flights.size();i++)
    {
        int node = flights[i][0];
        int nextNode = flights[i][1];
        int cost = flights[i][2];
        adj[node].push_back({nextNode,cost});
    }
    
    
    queue<pair<int,pair<int,int>>> bfs;


    for(pair<int,int> &p: adj[src])
    {
        bfs.push({0,p});

    }
    
    while(!bfs.empty())
    {
        while(!bfs.empty())
        {
            int wait = bfs.front().first ;
            int next = bfs.front().second.first;
            int cost = bfs.front().second.second ;
            bfs.pop();

            for(pair<int,int> &p: adj[next])
            {
                int newCost = cost + p.second;
                if(newCost < visited[next] and wait <k)
                {
                    visited[next] = newCost;
                    bfs.push({wait+1,p});
                }
            }
            
        }
    }
    return (visited[dst]==INT_MAX) ? -1: visited[dst] ;
}

int main()
{
    vector<vector<int>> flights{
        {0,1,100},
        {1,2,100},
        {2,0,100},
        {1,3,600},
        {2,3,200}
    };
    std::cout<<findCheapestPrice(4, flights,  0, 3, 1);
}