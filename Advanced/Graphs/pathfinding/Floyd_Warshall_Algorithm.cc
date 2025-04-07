#include"../includes.hpp"

// time complexity n^3
void floyd(std::vector<std::vector<int>> &graph)
{
    //great
    for(int via=0;via<graph.size();via++)
    {
	for(int u=0;u<graph.size();u++)
	{
		for(int v = 0;v<graph[0].size();v++)
		{
			graph[u][v]=std::min(graph[u][v],graph[u][via]+graph[via][v]);
		}
	}
    }

}


int main()
{
	
}
