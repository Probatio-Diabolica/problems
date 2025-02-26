#include"includes.hpp"


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    std::queue<int> bfs;
    std::vector<int> out(numCourses);
    std::unordered_map<int,std::vector<int>> mp;
    for(int i = 0;i<prerequisites.size();i++)
    {
        ++out[prerequisites[i][0]];
        mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for(int i=0;i<out.size();i++)
    {
        if(!out[i]) bfs.push(i);
    }

    while(!bfs.empty())
    {
        int currentNode=bfs.front();
        bfs.pop();
        for(int a:mp[currentNode])
        {
            --out[a];
            if(!out[a])
            {
                bfs.push(a);
            }
        }
    }
    for(int i=0;i<numCourses;i++)
    {
        if(out[i]>0) return false;
    }
    return true;
}

int main()
{
    iMat adj={{1,0},{1,2},{3,1},{3,2},{2,4},{4,5},{2,5}};
    std::cout<<canFinish(6,adj);
}