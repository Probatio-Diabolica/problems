#include<iostream>
#include<string.h>


int weight[105],values[105];

long long states[105][100005];


long long solution(int idx, int store)
{
    if(store==0) return 0;
    if(idx < 0) return 0;
    if(states[idx][store] !=-1) return states[idx][store];

    long long ans = solution(idx-1,store);
    if(store >= weight[idx]) ans = std::max(ans,solution(idx-1,store-weight[idx])+values[idx]);

    return states[idx][store] = ans;
}

int main()
{
    memset(states,-1,sizeof(states));
    int N,W;

    std::cin>>N>>W;

    for(int i = 0;i<N;i++)
    {
        std::cin>>weight[i]>>values[i];
    }

    std::cout<<solution(N-1,W);
}