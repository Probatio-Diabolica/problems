#include<iostream>
#include <cstdlib>




int main()
{
    while(true)
    {
        int n;
        std::cin>>n;
        if(n==42) exit(0);
        std::cout<<n<<'\n';
    }
}