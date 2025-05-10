#include "include.hpp"



int main()
{
    std::pair<int,int> dish1, dish2;

    std::cin>>dish1.first>>dish1.second;
    std::cin>>dish2.first>>dish2.second;

    int diffA = std::abs(dish1.first - dish1.second);
    int diffB = std::abs(dish2.first - dish2.second);

    if(diffA > diffB) std::cout<<"Second";
    else if(diffA < diffB) std::cout<<"First";
    else std::cout<<"Both";
}