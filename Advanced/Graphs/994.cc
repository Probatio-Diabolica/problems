#include"includes.hpp"


int orangesRotting(vector<vector<int>>& grid) {
    int fresh=0;
    int minutes=0;
    std::queue<std::pair<int,int>> bfs;

    for(int i =0;i<grid.size();i++)
    {
        for(int j =0;j<grid[0].size();j++)
        {
            if(grid[i][j] ==1) ++fresh;
            else if(grid[i][j]==2) bfs.push({i,j});
        }
    }
    while(!bfs.empty())
    {
        int run = bfs.size();
        int del = 0;
        while(run>0)
        {
            
            int row = bfs.front().first;
            int col = bfs.front().second;
            
            bfs.pop();

            if(row+1 < grid.size() and grid[row+1][col] == 1)
            {
                --fresh;
                grid[row+1][col] = 2;
                bfs.push({row+1,col});
                ++del;
            }
            if(row-1 >= 0  and grid[row-1][col] == 1)
            {
                --fresh;
                grid[row-1][col] = 2;
                bfs.push({row-1,col});
                ++del;
            }
            if(col+1 < grid.size() and grid[row][col+1] == 1)
            {
                --fresh;
                grid[row][col+1] = 2;
                bfs.push({row,col+1});
                ++del;
            }
            if(col-1 >= 0 and grid[row][col-1] == 1)
            {
                --fresh;
                grid[row][col-1] = 2;
                bfs.push({row,col-1});
                ++del;
            }
            --run;
        }
        if(del>0)++minutes;
    }

    return (fresh == 0 ) ?  minutes : -1;
}


int main()
{
    iMat graph={{1},{2}};
    std::cout<<orangesRotting(graph);
}