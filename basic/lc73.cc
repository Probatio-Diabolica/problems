#include "includes.hpp"
#include <cstddef>

void setRowZeros(vector<vector<int>>& matrix,queue<int>& q)
{
    while(!q.empty())
    {
        int row = q.front();
        q.pop();
        for(size_t i=0;i<matrix[row].size();i++)
        {
            matrix[row][i]=0;
        }
    }
}

void setColZeros(vector<vector<int>>& matrix,queue<int>& q)
{
    while(!q.empty())
    {
        int col = q.front();
        q.pop();
        for(size_t i=0;i<matrix.size();i++)
        {
            matrix[i][col]=0;
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    queue<int> rows,cols;
    unordered_map<int, int> rw,cl;
    for(size_t r=0;r<matrix.size();r++)
    {
        for(size_t c = 0; c<matrix[0].size();c++)
        {
            if(matrix[r][c]==0)
            {

                if(rw[r]==0) rows.push(r);
                if(cl[c]==0) cols.push(c);
                rw[r]=1;
                cl[c]=1;
            }
        }
    }

    setRowZeros(matrix, rows);
    setColZeros(matrix, cols);
}


int main()
{
    iMat mat{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(mat);
    std::cout<<mat;
}