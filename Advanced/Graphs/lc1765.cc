#include"includes.hpp"


vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    std::queue<std::pair<int,int>> source;
    for(int r = 0;r<isWater.size();r++)
    {
        for(int c=0;c<isWater[0].size();c++)
        {
            if(isWater[r][c]==1)
            {
                source.push({r,c});
                isWater[r][c]=0;
            }
            else isWater[r][c]=-1; 
        }
    }
    // TC=O(mxn)
    while(!source.empty())
    {
        int turn = source.size();

        while(turn >0)
        {
            int r = source.front().first;
            int c = source.front().second;
            source.pop();
            if((c+1 <isWater[0].size()) and (isWater[r][c+1]==-1))
            {
                isWater[r][c+1]=isWater[r][c]+1;
                source.push({r,c+1});
            }
            if((c-1 >-1) and (isWater[r][c-1]==-1))
            {
                isWater[r][c-1]=isWater[r][c]+1;
                source.push({r,c-1});
            }
            if((r+1 < isWater.size()) and (isWater[r+1][c]==-1))
            {
                isWater[r+1][c]=isWater[r][c]+1;
                source.push({r+1,c});
            }
            if((r-1 > -1) and (isWater[r-1][c]==-1))
            {
                isWater[r-1][c]=isWater[r][c]+1;
                source.push({r-1,c});
            }
            --turn;
        }
    }

    return isWater;
}

int main()
{

}