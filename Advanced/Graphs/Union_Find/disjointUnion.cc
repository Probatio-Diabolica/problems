#include"includes.hpp"

template <typename T>
void swap(T &a, T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

class Graph
{
public:
    iArray parent;
    iArray size;
    iArray rank;
public:
    Graph();
    void make_set(int v);
    int find_set(int v);
    void union_sets(int a, int b);
};

Graph::Graph()
{
    iArray arr(10);
    iArray si(10);
    iArray ra(10);
    for(int i = 0 ; i<10;i++)
    { 
        arr[i] = i;
        si[i]=i;
        ra[i]=i;
    }
    parent =  std::move(arr);
    size = std::move(si);
    rank=std::move(ra);
}

void Graph::make_set(int v)
{
    // Size based optimization
    // parent[v]=v;
    // size[v] = 1;

    //rank based optimization
    parent[v]=v;
    rank[v]=v;
}


int Graph::find_set(int v)
{
    if(v==parent[v]) return v;
    
    //// old
    // return find_set(parent[v]);

    //// new 
    return parent[v]= find_set(parent[v]);
}

void Graph::union_sets(int a, int b)
{
    //// Old 
    a = find_set(a);
    b = find_set(b);
    // if( a!=b) parent[b] = a;

    //// Size based implementation
    // a = find_set(a);
    // b = find_set(b);
    // if(a!=b)
    // {
    //     if(size[a] < size[b]) swap(a,b);
    //     parent[b] = a;
    //     size[a] +=size[b];
    // }

    //// rank based depth of a tree
    if(a!=b)
    {
        if(rank[a] < rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) ++rank[a];
    }

}

int main()
{
    Graph g = Graph();
    std::cout<<"Original ::--------------------\n"<<g.parent<<'\n'<<g.size;
    // for()int 
    for(int i =0 ;i < 10;i++)
    {
        g.find_set(i);
        // g.union_sets(2,i);
    }
    for(int i =0 ;i < 10;i++)
    {
        // g.find_set(i);
        g.union_sets(9-i,i);
    }
    std::cout<<"new ::------------------\n"<<g.parent<<'\n'<<g.size;
}