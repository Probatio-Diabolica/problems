#include "include.hpp"
#include <unordered_map>

void solve(int N, int K)
{
    iArray result(K);
    

    for(int i=1;i<=N;i++)
    {
        int x = i%K;
        for(int j=1;j<=N;j++)
        {
            if(j%K == i%K and i !=j) ++result[x];
        }
    }
    
    // std::cout<<
}


int main()
{
    int T , N , K;
    std::cout<<T;
    while(T>0)
    {
        std::cin>>N >> K;
        solve(N,K);
        --T;
    }
}