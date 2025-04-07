#include "includes.hpp"


int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start==end) return 0;
    int steps=0;
    queue<int> bfs;
    bfs.push({start});
    unordered_map<int, bool> map;
    map[start] = true;
    while(!bfs.empty())
    {
        int size = bfs.size();
        while(size>0)
        {
            int now = bfs.front();
            bfs.pop();

            for(int i:arr)
            {
                int next = (now * i )%100000;
                if(next == end) return steps+1;
                if(!map[next])
                {
                    bfs.push(next);
                    map[next] = true;
                }
            }
            --size;
        }
        ++steps;
    }

    return -1;
}



int main()
{
    iArray vec{3,4,65};
    std::cout<<minimumMultiplications(vec, 7,66175 );
}