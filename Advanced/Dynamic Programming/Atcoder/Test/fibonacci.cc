#include <bits/stdc++.h>

int fibo(int n, std::vector<int> &dp)
{
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];

    return dp[n]=fibo(n-1,dp) + fibo(n-2,dp);
}

// tc = n , sp = n(recusrive stack) + n(vector)
int main()
{
    int n = 20;
    std::vector<int> dp(n+1,-1);
    std::cout<<fibo(n, dp)<<'\n';
}