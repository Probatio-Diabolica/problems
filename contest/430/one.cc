#include<iostream>
#include<vector>

using namespace std;

int minimumOperations(vector<vector<int>>& grid) {
    int op=0;
    if(grid.size()<2) return 0;
    for(int r=1;r<grid.size();r++)
    {
        for(int c=0;c<grid[0].size();c++)
        {
            int diff= (grid[r-1][c]-grid[r][c]) +1;
            diff= (diff > 0) ? diff : 0;
            op+=diff;
            grid[r][c]+=diff;
        }
    }
    return op;
}

int main()
{
    vector<vector<int>> a={{3,2,1},{2,1,0},{1,2,3}},b{{3,2},{1,3},{3,4},{0,1}},c={{1,2,3},{1,2,4}};
    std::cout<<minimumOperations(c);
}