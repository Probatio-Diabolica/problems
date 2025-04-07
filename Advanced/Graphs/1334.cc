#include "includes.hpp"
#include <climits>


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    
    vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
    // {num. nodes , node number}
    auto fit = [](pair<int,int>& x,pair<int,int>& y)
    {
        if(x.first == y.first)
        {
            return (x.second < y.second) ; //big priority for bigger number 
        }
        else 
        {
            return (x.first > y.first) ; //small priority for distance
        }
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(fit)> myHeap(fit);
    for(auto &x : edges)
    {
        int src = x[0];
        int dist = x[1];
        int weight = x[2];
        graph[src][dist] = weight;
    }
    for(int src=0;src<n;src++)
    {
        int amt = 0;
        int distance = 0;
        for(int dist=0;dist<n;dist++)
        {
            
            if(graph[src][dist] != INT_MAX )
            {
                int temp = distance + graph[src][dist];
                if(temp < distanceThreshold)
                {
                    distance = temp;
                    myHeap.push({distance,src});    
                }
            }
        }
    }

    return myHeap.top().second;
}

int main()
{

}