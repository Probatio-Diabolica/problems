#include <unordered_map>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using node = int;
using nextNode = vector<int>;



void bfs(unordered_map<node, nextNode> &adj,int &count,int n)
{
    queue<node> q;
    q.push(1);

    vector<bool> visited(n+1,false);
    visited[1]=true;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int node:adj[curr])
        {
            if(!visited[node])
            {
                ++count;
                visited[node]=true;
                q.push(node);
            }
        }
    }
}


int main()
{
    int n, m,x;
    cin>>n>>m;
    x=m;
    unordered_map<node, nextNode> adj;



    if(n!=m) cout<<"No\n";
    else
    {
        while(x--)
        {
            int now , next;
            cin>>now>>next;
            adj[now].push_back(next);
            adj[next].push_back(now);
        }

        for(int i =1;i<n+1;i++)
        {
            if(adj[i].size()!=2) 
            {
                cout<<"No\n";
                return 0;
            }
        }

        int count =1;
        bfs(adj, count, n);
        if(count==n) cout<<"Yes\n";
        else cout<<"No\n";
    }

}