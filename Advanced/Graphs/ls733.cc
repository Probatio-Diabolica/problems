#include"includes.hpp"

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
    int orignal= image[sr][sc];
    if(orignal==color) return image;
    std::queue<std::pair<int,int>> tracer;
    tracer.push({sr,sc});
    image[sr][sc]=color;
    
    while(!tracer.empty())
    {
        int r=tracer.front().first;
        int c=tracer.front().second;
        tracer.pop();
        if((r+1)<image.size() and image[r+1][c] == orignal)
        {
            image[r+1][c]=color;
            tracer.push({r+1,c});
        }
        if((r-1)>-1 and image[r-1][c] == orignal)
        {
            image[r-1][c]=color;
            tracer.push({r-1,c});
        }
        if((c+1)<image[0].size() and image[r][c+1] == orignal)
        {
            image[r][c+1]=color;
            tracer.push({r,c+1});
        }
        if((c-1) >-1 and image[r][c-1] == orignal)
        {
            image[r][c-1]=color;
            tracer.push({r,c-1});
        }
    }
    return image;
}



int main()
{
    iMat mat={
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    std::cout<<floodFill(mat,1,1,2);
}