#include"includes.hpp"


int orangesRotting(vector<vector<int>>& grid) {
    int vertices=grid.size();
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
        while(run>0)
        {
            int row = bfs.front().first;
            int col = bfs.front().second;
            
            bfs.pop();

            

            --run;
        }
        ++minutes;
    }

    return minutes;
}


int main()
{
    iMat graph={{}};

}