#include"includes.hpp"


int lastStoneWeight(vector<int>& stones) {
    maxHeap heap;
    for(int i=0;i<stones.size();i++)
    {
        heap.push(stones[i]);
    }

    while(heap.size()>1)
    {
        int a=heap.top();
        heap.pop();
        int b= heap.top();  
        heap.pop();
        a-=b;
        if(a>0) heap.push(a);
    }
    if(heap.size()==0) return 0;
    return heap.top();
}

int main()
{
    iArray x={4,3,4,3,2};
    std::cout<<lastStoneWeight(x);
}