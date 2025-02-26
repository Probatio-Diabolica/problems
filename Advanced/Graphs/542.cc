#include"includes.hpp"
// TC : O(m*N)
// SC: O(M*N)
// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
// {
//     std::queue<std::pair<int,int>> rollStack;
//     int rSize=mat.size(),cSize=mat[0].size();
//     // preprocessing : O(m*n)
//     for(int r=0;r<mat.size();r++)
//     {
//         for(int c=0;c<mat[0].size();c++)
//         {
//             if(mat[r][c]==0) rollStack.push({r,c});
//             else mat[r][c] = -1;
//         }
//     }

//     while(!rollStack.empty())
//     {
//         int r = rollStack.front().first;
//         int c = rollStack.front().second;
//         rollStack.pop();

//         if((r+1) < rSize and mat[r+1][c] ==-1) 
//         {
//             mat[r+1][c]=mat[r][c]+1;
//             rollStack.push({r+1,c});
//         }
        
//         if((r-1) > -1 and mat[r-1][c] ==-1) 
//         {
//             mat[r-1][c]=mat[r][c]+1;
//             rollStack.push({r-1,c});
//         }
//         if((c+1) < cSize and mat[r][c+1] ==-1){
//             mat[r][c+1]=mat[r][c]+1;
//             rollStack.push({r,c+1});
//         } 

//         if((c-1) > -1 and mat[r][c-1] ==-1) 
//         {
//             mat[r][c-1]=mat[r][c]+1;
//             rollStack.push({r,c-1});
//         }
//     }

//     return mat;
// }

int min(int a,int b)
{
    return a> b ? b : a;
}
//best o(M*N) no space
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size(), INF = m + n; // The distance of cells is up to (M+N)
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (mat[r][c] == 0) continue;
            int top = INF, left = INF;
            if (r - 1 >= 0) top = mat[r - 1][c];
            if (c - 1 >= 0) left = mat[r][c - 1];
            mat[r][c] = min(top, left) + 1;
        }
    }
    for (int r = m - 1; r >= 0; r--) {
        for (int c = n - 1; c >= 0; c--) {
            if (mat[r][c] == 0) continue;
            int bottom = INF, right = INF;
            if (r + 1 < m) bottom = mat[r + 1][c];
            if (c + 1 < n) right = mat[r][c + 1];
            mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
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