#include"includes.hpp"

int DP(int idx,int amount,vector<int>&coins,vector<vector<int>>& states)
{
    if(amount == 0) return 1;
    if(idx < 0) return 0;
    if(states[idx][amount]!= -1) return states[idx][amount];
    int ways = 0;
    for(int amt=0;amt<=amount;amt+=coins[idx])
    {
        ways+=DP(idx-1,amount-amt,coins,states);
    }
    return states[idx][amount]=ways;
}

int change(int amount, vector<int>& coins) {
    vector<vector<int>> states(300,vector<int>(1e5+10,-1));
    return DP(coins.size()-1,amount,coins,states);
}



int main()
{
    iArray a={1,2,5};
    cout<<change(5,a);
}