#include<iostream>
#include <numeric>

long long solution(int keyA, int keyB)
{
    long long sol=1;
    sol = std::abs(keyA*keyB)/std::gcd(keyA, keyB) ;
    return sol;
}

int main()
{
    int t;
    std::cin>>t;
    while(--t >-1)
    {
        int a,b;
        std::cin>>a>>b;
        std::cout<<solution(a,b)<<'\n';
    }
}