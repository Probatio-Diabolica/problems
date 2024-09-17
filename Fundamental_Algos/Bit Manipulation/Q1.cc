#include<iostream>
#include<cstdint>

void betterSwap(int * a, int *b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}


int main()
{
    // std::cout<<minBitFlips(0,1)<<"\n";
    // std::cout<<minBitFlips(10,1)<<"\n";
    // std::cout<<minBitFlips(23,11)<<"\n";
    // std::cout<<minBitFlips(10,1)<<"\n";
    int a=90,b=89;betterSwap(&a,&b);
    std::cout<< a;

}