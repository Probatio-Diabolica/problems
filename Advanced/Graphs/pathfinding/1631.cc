#include "../includes.hpp"




using node = std::pair<int,std::pair<int,int>>;

int minimumEffortPath(vector<vector<int>>& heights) {
    // minheap for storing the smallest difference at the top 
    std::priority_queue<node,
    vector<node>,
    std::greater<node>> pq; 
    
    int row = heights.size();
    int col = heights[0].size();

    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};

    vector<vector<int>> difference(row,vector<int>(col,INT_MAX));


    // TC:E log V
    while(!pq.empty())
    {
        int diff =  pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if(x==row-1 and y==col-1) return diff;

        //go for the ways
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // check for the validity
            if(nx>-1 and nx<row and ny>-1 and ny <col)
            {   
                int newEffort = std::max(std::abs(heights[x][y]-heights[nx][ny]),diff);

                if(newEffort < difference[nx][ny])
                {
                    difference[nx][ny] = newEffort;
                    pq.push({newEffort,{nx,ny}});
                }
            }            
        }


    }


    return 0;
}


int main()
{
    iMat graph={{1,2,2},{3,8,2},{5,3,5}};
    std::cout<<minimumEffortPath(graph);
}