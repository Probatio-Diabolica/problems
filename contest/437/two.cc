#include"include.hpp"

long long maxWeight(vector<int>& pizzas) {
    std::priority_queue<int> maxheap;
    long long sol=0;
    for(int i=0;i<pizzas.size();i++)
    {
        maxheap.push(pizzas[i]);
    }

    int poss = pizzas.size()/4;
    std::vector<int> arb(poss,0);
    for(int i=0;i<(pizzas.size()/4);i++)
    {
        arb[i]=maxheap.top();
        maxheap.pop();
    }
    int x = (poss & 1) ? (int)((float)poss/2 + 0.5) : poss/2;
    while(x<poss)
    {
        arb[x]=maxheap.top();
        maxheap.pop();
        ++x;
    }

    for(int i=0;i<poss;i++)
    {
        sol+=arb[i];
    }
    return sol;
}

int main()
{
    // iArray a={5,2,2,4,3,3,1,3,2,5,4,2};
    iArray a ={1,2,3,4,5,6,7,8};
    std::cout<<maxWeight(a);
}