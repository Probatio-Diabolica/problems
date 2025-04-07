#include<iostream>

int main()
{
    int t,a,b;
    std::cin>>t;
    while(--t>-1)
    {
        std::cin>>a>>b;
        std::cout<<(b-a)<<'\n';
    }
}