#include<iostream>

int main() {
    int t;
    std::cin>>t;
    while(--t >-1)
    {
        int x, y , z;
        std::cin>>x>>y>>z;
         (((float)z/(x*y)) > 0.5) ? std::cout<<"YES\n" : std::cout<<"NO\n" ; 
    }
}
