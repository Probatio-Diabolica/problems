#include "../includes.hpp"
#include <climits>

// int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
//                       int k) {

//   std::vector<int> visited(n, INT_MAX);
//   visited[src] = 0;
//   vector<vector<pair<int, int>>> adj;

//   for (int i = 0; i < flights.size(); i++) {
//     int node = flights[i][0];
//     int nextNode = flights[i][1];
//     int cost = flights[i][2];
//     adj[node].push_back({nextNode, cost});
//   }

//   queue<pair<int, pair<int, int>>> bfs;

//   bfs.push({0, {src, 0}});

//   while (!bfs.empty()) {
//     int airport = bfs.front().first;
//     int next = bfs.front().second.first;
//     int cost = bfs.front().second.second;
//     bfs.pop();

//     if (airport > k) continue;

//     for (pair<int, int> &p : adj[next]) {
//       int newCost = cost + p.second;
//       int nextNode=p.first;
//       if (newCost < visited[next] and airport <= k ) 
//       {
//         visited[nextNode] = newCost;
//         bfs.push({airport + 1, {nextNode, newCost}});
//       }
//     }
//   }

//   return (visited[dst] == INT_MAX) ? -1 : visited[dst];
// }

int findCheapestPrice(int n, vector<vector<int>> &flights,
    int src, int dst, int K)
{
    // Create the adjacency list to depict airports and flights in
    // the form of a graph.
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
    adj[it[0]].push_back({it[1], it[2]});
    }

    // Create a queue which stores the node and their distances from the
    // source in the form of {stops, {node, dist}} with ‘stops’ indicating 
    // the no. of nodes between src and current node.
    queue<pair<int, pair<int, int>>> q;

    q.push({0, {src, 0}});

    // Distance array to store the updated distances from the source.
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // Iterate through the graph using a queue like in Dijkstra with 
    // popping out the element with min stops first.
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        // We stop the process as soon as the limit for the stops reaches.
        if (stops > K) continue;
        for(auto iter : adj[node])
        {
            int adjNode = iter.first;
            int edW = iter.second;

            // We only update the queue if the new calculated dist is
            // less than the prev and the stops are also within limits.
            if (cost + edW < dist[adjNode] && stops <= K)
            {
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }
    // If the destination node is unreachable return ‘-1’
    // else return the calculated dist from src to dst.
    if (dist[dst] == 1e9) return -1;
    return dist[dst];
}

int main() {
  vector<vector<int>> flights{
      {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  std::cout << findCheapestPrice(4, flights, 0, 3, 1);
}