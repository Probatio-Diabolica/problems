#include <iostream>



int main()
{
    int t,n;
    std::cin>>t;
    while(--t>-1)
    {
        std::cin>>n;
        unsigned long long x=n * 2; 
        std::cout<<x<<'\n';
    }
}