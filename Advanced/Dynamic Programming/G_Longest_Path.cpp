#include "includes.hpp"

int max(int a, int b)
{
    return a>b ? a : b;
}

int maxLen(int src, int des,std::vector<bArray> &graph)
{
    if(src < 0 or des < 0) return 0;

    int solution=0;
    for(int source =src;source<graph.size();source++)
    {
        for(int dest=des;dest<graph.size();dest++)
        {
            if(graph[source][dest]) solution= max(solution, maxLen(source+1,dest,graph))+1;
        }
    }
    return solution;
}


int main()
{
    int N,M;
    std::cin>>N>>M;
    std::vector<bArray> graph(N,bArray(N));

    while(M>0)
    {
        int v1,v2;
        std::cin>>v1>>v2;
        graph[v1-1][v2-1]=true;
        --M;
    }
    
    std::cout<<maxLen(0,0,graph);
}