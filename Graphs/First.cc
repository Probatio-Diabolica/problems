#include<iostream>
#include<unordered_map>
#include<list>

template <typename Type>
struct Graph
{
    Type node;
    int degree;
    std::list<Type> lists;
    std::unordered_map<Type,std::list<Type>> adj;
    
    // Graph(Type out_node): node(out_node)
    // {
    //     degree;
    //     lists.push_back(nullptr);
    // }

    void addEdge(int u,int v,bool direction)
    {

    }

};


int main()
{

}