#include<iostream>

template <typename T>
T bits(T x,T y)
{
    return x xor y;
}



int main()
{

    std::cout<<bits(61,90);
}