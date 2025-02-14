#include"includes.hpp"

long long min(long long a, long long b)
{
    return a>b ? b : a;
}
////////// TC :: O(N) where N is the number of possible states, 
int DFS(int amount , vector<int>& coins,vector<int>& states)
{
    if(amount==0) return 0;
    if(states[amount]!=-1) return  states[amount];

    int sol=INT32_MAX;
    for(int i=0;i<coins.size();i++)
    {
        if(amount >= coins[i] )
        {
            sol=min(sol + 0LL ,DFS(amount-coins[i],coins,states)+1LL);
        }
    }
    return states[amount]=sol;
}

int coinChange(vector<int>& coins, int amount) 
{
    vector<int> states(1e4+10,-1);
    int sol=DFS(amount,coins,states);
    return sol==INT32_MAX ? -1 : sol;
}


int main()
{
    iArray x={1,2,5},y={2},z={1};
    cout<<coinChange(y,3)<<" || "<<coinChange(x,11)<<"||"<<coinChange(z,0)<<"\n";
}
