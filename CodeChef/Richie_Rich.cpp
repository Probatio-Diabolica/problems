#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t ; 
    std::cin>>t;
    int a , b , x;
    while(--t>-1)
    {
        std::cin>> a >> b>>x;
        std::cout<< ((float)b-a)/x <<'\n';
    }
}
