#include<iostream>
#include<vector>
#include<stack>

int largestRectangleArea(std::vector<int>& heights) 
{
    if(heights.size()==1) return heights[0];
    int solution=0,left=0,maxSol=heights[0];
    for(int right=0;right<heights.size();right++)
    {
        if(heights[left]<=heights[right])
        {
            solution=((right-left)+1 )* heights[left];
            if(maxSol<solution) maxSol=solution;
        
        } else if(heights[left]>heights[right]){
            left=right;
        }
    }
    return maxSol;
}
int main()
{
    std::vector<int> h={2,1,5,6,2,3}, ec={9};
    std::cout<<largestRectangleArea(h);
}