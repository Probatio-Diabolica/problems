#include<iostream>
#include<vector>

int main()
{
    int t;
    std::cin>>t;
    while(--t>-1)
    {
        int k ;
        std::cin>>k;
        std::cout<<((k&1) ? "YES\n" : "NO\n");
    }
}