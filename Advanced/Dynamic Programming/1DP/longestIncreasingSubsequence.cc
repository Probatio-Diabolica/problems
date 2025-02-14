#include"includes.hpp"

int DFS(std::vector<int>& nums , int pos,std::vector<int>& states)
{
    if(states[pos]!=-1) return states[pos];
    int sol=1;
    for(int i=0;i<pos;++i)
    {
        if(nums[pos] > nums[i])
        {
            sol = max(sol,DFS(nums,i,states)+1);
        }
    }
    return states[pos]=sol;
}

int lengthOfLIS(std::vector<int>& nums) 
{
    std::vector<int> states(nums.size(),-1);
    int solution=0;
    for(int i=0;i<nums.size();++i)
    {
        solution=max(solution,DFS(nums,i,states));
    }
    return solution;
}






int main()
{
    iArray x={10,9,2,5,37,101,18};

    cout<<lengthOfLIS(x);
}