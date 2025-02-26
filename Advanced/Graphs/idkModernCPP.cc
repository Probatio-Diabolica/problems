#include"include.hpp"


template <typename T>
struct Graph
{
    T data;
    void put(const adGraph& graph)
    {
        data=std::move(graph);
    }
};

int main()
{
    // adGraph m={{1,2,3},{1,2,3},{1,2,3}};
    Graph<adGraph> g;
    g.put({{1,2,3},{1,2,3},{1,2,3}});
    // g.put(m);
    //m is unuasble now
    return 0;
}
