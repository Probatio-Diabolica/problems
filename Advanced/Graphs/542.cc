#include"includes.hpp"

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
{
    std::queue<std::pair<int,int>> rollStack;
    int rSize=mat.size(),cSize=mat[0].size();
    // preprocessing : O(m*n)
    for(int r=0;r<mat.size();r++)
    {
        for(int c=0;c<mat[0].size();c++)
        {
            if(mat[r][c]==0) rollStack.push({r,c});
            else mat[r][c] = -1;
        }
    }

    while(!rollStack.empty())
    {
        int r = rollStack.front().first;
        int c = rollStack.front().second;
        rollStack.pop();

        if((r+1) < rSize and mat[r+1][c] ==-1) 
        {
            mat[r+1][c]=mat[r][c]+1;
            rollStack.push({r+1,c});
        }
        
        if((r-1) > -1 and mat[r-1][c] ==-1) 
        {
            mat[r-1][c]=mat[r][c]+1;
            rollStack.push({r-1,c});
        }
        if((c+1) < cSize and mat[r][c+1] ==-1){
            mat[r][c+1]=mat[r][c]+1;
            rollStack.push({r,c+1});
        } 

        if((c-1) > -1 and mat[r][c-1] ==-1) 
        {
            mat[r][c-1]=mat[r][c]+1;
            rollStack.push({r,c-1});
        }
    }

    return mat;
}


int main()
{
    iMat mat={
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    std::cout<<updateMatrix(mat);
}