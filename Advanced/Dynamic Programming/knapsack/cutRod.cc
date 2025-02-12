#include"includes.hpp"
// Unbounded knapsack

vector<int> dp(1005,-1);

int max(int i , int j)
{
    return i> j ? i : j;
}
int cost(int len, vector<int>& prices)
{
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len]; 
    int solution=0;
    for(int cut=1;cut<=prices.size();++cut)
    {
        if(cut <= len) solution= max(solution, cost(len-cut,prices) + prices[cut-1]);
    }
    return dp[len]=solution;
}


int cutRod(vector<int> &price) {
    return cost(price.size(),price);
}


int main()
{
    iArray a= {1, 5, 8, 9, 10, 17, 17, 20};

    std::cout<<cutRod(a);
}