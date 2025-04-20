#include <iostream>

int main() {
    int t , x , y;
    std::cin>>t;

    while(--t >-1)
    {
        std::cin>>x>>y;
        std::cout<< (x * 4) + y<<'\n';
    }
    
}
