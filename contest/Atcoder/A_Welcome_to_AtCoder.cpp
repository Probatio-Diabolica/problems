#include<iostream>


int main()
{
    int a,b,c;
    std::string s;
    while(std::cin>> a>>b>>c>>s)
    {
        std::cout<< (a+b+c) <<" "<<s;
    }
}