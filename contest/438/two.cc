#include<iostream>
#include<vector>
#include<queue>
using std::vector,std::priority_queue;

long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    long long sol=0;
    priority_queue<int> maxHeap;
    for(int j=0;j<grid.size();j++)
    {
        priority_queue<int> t__maxHeap;
        for(int curr=0;curr<grid[j].size();curr++)
        {
            t__maxHeap.push(grid[j][curr]);
        }
        for(int temp=0;temp<limits[j];temp++)
        {
            maxHeap.push(t__maxHeap.top());
            t__maxHeap.pop();
        }
    }
    for(int i =0;i<k;i++)
    {
        sol+=maxHeap.top();
        maxHeap.pop();
    }
    return sol;
}


int main()
{
    vector<vector<int>> g={{5,3,7},{8,2,6}};
    vector<int> limit={2,2};
    std::cout<<maxSum(g,limit,3);
}