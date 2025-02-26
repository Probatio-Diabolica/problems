#include"includes.hpp"

bool DFS(std::vector<int>& nodes,int currentNode, std::vector<int> &color,int currColor)
{
    color[currentNode]=currColor;
    for(int curr:nodes)
    {
        
        if(color[curr]==-1)
        {
            int newColor= 1-currColor;
            if(!DFS(nodes,curr,color,newColor)) return false;
        }
        else if(color[curr]==currColor) return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) 
{
    std::vector<int> color(graph.size(),-1);
    int black=0;
    // color[0]=black;
    // for(int node=0;node<graph.size();node++)
    // {
    //     // if(color[node]==-1) color[node]=black;
    //     for(int current=0;current<graph[node].size();current++)
    //     {
    //         if(color[graph[node][current]]==-1) 
    //         color[graph[node][current]] = !color[node];
            
    //         if(color[graph[node][current]]==color[node]) 
    //         return false;

    //     }
    // }

    for(int i=0;i<graph.size();i++)
    {
        if(color[i]==-1)
        {
            if(!DFS(graph[i],i,color,black)) return false;
        }
    }
    return true;

}

// Line 1122: Char 34: runtime error: addition of unsigned offset to 0x502000000190 overflowed to 0x501efafafc88 (stl_vector.h)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_vector.h:1131:34

int main()
{
    iMat graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    iMat graph2={{1,3},{0,2},{1,3},{0,2}};
    std::cout<<isBipartite(graph)<<'\n';
    std::cout<<isBipartite(graph2);
}