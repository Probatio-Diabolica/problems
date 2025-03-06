#include "../includes.hpp"
#include <climits>
#include <type_traits>
#include <vector>

// Uses BFS
// vector<vector<int>> dirs={{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
// int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//     int row=grid.size();
//     int col= grid[0].size();
    
//     if(row==0 || col==0) return -1;
    
//     if(grid[0][0]!=0 | grid[row-1][col-1]!=0) return -1;
//     grid[0][0] = 1;
//     queue<pair<int, int>> q;
//     q.push({0,0});

//     while(!q.empty()){
//         auto curr= q.front();
//         int x= curr.first;
//         int y= curr.second;
    
//         if(x==row-1 && y==col-1) return grid[x][y];

//         for(auto direction : dirs){
//             int nx= x+ direction[0];
//             int ny= y+ direction[1];
//             if(nx >=0 && nx<row && ny>=0 && ny<col && grid[nx][ny]==0){
//                 q.push({nx, ny});
//                 grid[nx][ny]= grid[x][y]+1;
//             }

//         }
//         q.pop();

//     }
//     return -1;
// }



// By dijkstra 
int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{

    if(grid[0][0] or grid[grid.size()-1][grid[0].size()-1]) return -1;

    vector<vector<int>> directions{{0,1},{0,-1},{-1,0},{-1,1},{-1,-1},{1,0},{1,-1},{1,1}};

    priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,std::greater<pair<int, pair<int,int>>>> pq;

    vector<vector<int>> visited(grid.size(),(vector<int>(grid[0].size(),INT_MAX))) ;

    auto isSafe = [&](int x, int y)
    {
        return x>=0  and x < grid.size() and y >=0 and y < grid[0].size();
    };

    pq.push({0,{0,0}});
    visited[0][0] = 0;

    while(!pq.empty())
    {
        int dist = pq.top().first;
        pair<int,int> node = pq.top().second;

        int x = node.first;
        int y = node.second;

        pq.pop();

        for(auto dir:directions)
        {
            int nx = x+dir[0];
            int ny = y+dir[1];

            int distance = 1;

            if(isSafe(nx, ny) and grid[nx][ny]==0 and distance+dist < visited[nx][ny])
            {
                pq.push({dist+distance , {nx,ny}});
                visited[nx][ny] = dist+distance;
            }
        }

    }


    return (visited[grid.size()-1][grid[0].size()-1] == INT_MAX) ? -1 : visited[grid.size()-1][grid[0].size()-1]+1L;
}


int main()
{
    // vector<vector<int>> vec={{0,0,0},{1,1,0},{1,1,0}};
    // vector<vector<int>> vec = {{0,1,0,1,0},{1,0,0,0,1},{0,0,1,1,1},{0,0,0,0,0},{1,0,1,0,0}};
    vector<vector<int>> vec = {{0,1,0},{1,1,0},{1,1,0}};
    // vector<vector<int>> vec = {{0,1},{1,0}};
    // std::cout<<vec;
    std::cout<<shortestPathBinaryMatrix(vec);
}