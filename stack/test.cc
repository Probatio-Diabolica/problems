#include<iostream>

int main()
{
    std::pair<int,int> a={1,2};
    std::pair<int,int> b=a;
    std::cout<<b.first;
}