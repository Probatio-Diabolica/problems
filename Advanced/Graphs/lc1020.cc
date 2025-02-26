#include"includes.hpp"


void dfs(int r,int c,vector<vector<int>>& grid)
{
    if(r<0 or c<0 or r==grid.size() or c==grid[0].size() or grid[r][c]!=1) return;
    grid[r][c]=2;
    dfs(r+1 ,c ,grid);
    dfs(r-1 ,c ,grid);
    dfs(r ,c+1 ,grid);
    dfs(r ,c-1 ,grid);
}


int numEnclaves(vector<vector<int>>& grid) {
    int enclaves=0;
    int rows=grid.size(),cols=grid[0].size();
    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<cols;c++)
        {
            if((c==0 or c==cols-1) or (r==0 or r == rows-1)) dfs(r,c,grid);
        }
    }
    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<cols;c++)
        {
            if(grid[r][c]==1) ++enclaves;
        }
    }
    return enclaves;
}


int main()
{
    iMat mat={
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    std::cout<<mat;
    std::cout<<numEnclaves(mat);
}