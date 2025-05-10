#include<iostream>
#include <ostream>
#include<vector>

using idx = int;
using max = int;
using iMat = std::vector<std::vector<int>>;
int rowWithMax1s(std::vector<std::vector<int>> &arr) {
    std::pair<max,idx> p{-1,-1};
    int x =0;
    for(std::vector<int>& v:arr)
    {
        int head = 0 , tail = v.size(), mid;
        while(head<=tail)
        {
            mid = head + (tail-head)/2;
            if(v[mid]==1) tail = mid-1;
            else  head = mid + 1;
        }
        int one_count = v.size() - head; 
        if(p.first < (one_count) and one_count > 0) p.first=(one_count),p.second=x; 
        ++x;
    }
    return p.second;
}

int main()
{
    // std::vector<std::vector<int>> vec{{0,1,1,1}, {0,0,1,1}, {1,1,1,1}, {0,0,0,0}};
    iMat f{{0,0,0},{0,1,1},{1,1,1},{0,0,1},{1,1,1},{0,0,1},{1,1,1},{0,0,0},{0,1,1}};
    std::cout<<rowWithMax1s(f)<<std::endl;
}