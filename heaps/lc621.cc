#include"includes.hpp"



int leastInterval(vector<char>& tasks, int n) 
{
    int mp[26];
    for(char& ch: tasks)
    {
        ++mp[ch-'A'];
    }
    int time = 0;
    std::priority_queue<int> pq;
    for(int i =0;i<26;i++)
    {
        if(mp[i]>0) pq.push(mp[i]);
    }


    while (!pq.empty())
    {
        std::vector<int> temTasks;
        for(int i=1;i<=n+1;i++)
        {
            if(!pq.empty())
            {
                int freq = pq.top()-1;
                pq.pop();
                temTasks.push_back(freq);                    
            }
        }

        for(int &freq:temTasks)
        {
            if(freq>0)
            {
                pq.push(freq);
            }
        }

        if(pq.empty()) time += temTasks.size();
        else time += n+1;
    }
    return time;
}


int main()
{
    std::vector<char> x={'A','A','A','B','B','B'};
    std::cout<<leastInterval(x,2);
}