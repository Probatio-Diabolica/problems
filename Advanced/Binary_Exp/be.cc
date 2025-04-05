#include <climits>
#include <iostream>
#include <sys/types.h>

int main()
{
    unsigned long long a =2,b=32;
    unsigned long long res=1;
    while(b)
    {
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    std::cout<<res<<' '<<INT_MAX;
}