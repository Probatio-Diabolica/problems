#include"include.hpp"


int aacx(int x, int y)
{
    return x+y;
}

int y(int (*fntr)(int,int))
{
    return fntr(90,190);
}
int main()
{
    std::cout<<y(aacx);
}

