#include<iostream>
#include<string.h> 
constexpr int N=1e3+10;

int values[100];
int weight[100];
int states[100][N];
inline long long min(long long a, long long b)
{
    return a > b ? b : a;
}

long long Solution(int idx,int valRemaining)
{
    if(valRemaining == 0) return 0;
    if(idx < 0 ) return __LONG_LONG_MAX__;

    //Let's not take this value
    long long answer = Solution(idx-1,valRemaining);
    // Let's take this value
    if(valRemaining>= values[idx]) 
        answer=min(answer,Solution(idx,valRemaining-values[idx]) + weight[idx] );

    return answer;
}


int main()
{
    memset(states,-1,sizeof(states));
    int n,w;
    std::cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        std::cin>>weight[i] >> values[i];
    }
    long long sol= __LONG_LONG_MAX__;
    for(int i=0;i<n;i++)
    {
        if()
    }
    cout<<
}









