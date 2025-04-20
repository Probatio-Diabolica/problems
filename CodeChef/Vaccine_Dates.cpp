#include <iostream>
// using namespace std;

int main() 
{
    int t ;
    long long  d, l , r ;
    std::string ok = "Take second dose now\n",late="Too Late\n",early="Too Early\n";
    std::cin>>t;
    while(--t > - 1)
    {
        std::cin>> d >> l >> r;

        if(d >=  l and d <= r) std::cout<<ok;
        else if (d > r) std::cout<<late;
        else std::cout<<early;
    }

}
