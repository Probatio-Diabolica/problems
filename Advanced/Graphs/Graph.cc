#include"include.hpp"

// constexpr int N=4;
// adGraph a(N+1,iArray(N,0));


int main()
{
    int N,M;
    // N => No. of vertices [Nodes]
    // M => no of edges [path/way]
    std::cin>>N>>M;

    bMat gr(N+1,bArray(N+1));

    for(int i =0;i<M;++i)
    {
        std::cout<<"Node\n";
        int v1,v2;
        std::cin>>v1>>v2;
        gr[v1][v2]=1;
        gr[v2][v1]=1;
        gr[v1][v1]=1;
        gr[v2][v2]=1;
    }
    std::cout<<gr;
}

