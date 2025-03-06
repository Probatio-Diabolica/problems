#include "include.hpp"

int lastRemaining(int n) 
{
    return (n==1) ? 1 : 2 * ((n/2 +1 )- lastRemaining(n/2));
}

int main()
{
    std::cout<<lastRemaining(9);
}