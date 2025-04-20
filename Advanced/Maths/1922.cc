#include<iostream>

int modPow(int base ,long long exp)
{
    int m = 1e9 + 7;
    int res=1;
    base %= m;
    while(exp)
    {
        if(exp&1) res = (long long)res* base%m;
        base = (long long)base*base%m;
        exp >>= 1;
    }
    return res;
}

int countGoodNumbers(long long n) {
    int m = 1e9 + 7;
    return (long long)modPow(5,(n+1)/2) * modPow(4, n/2) %m; 
}

int countGoodNumbers2(long long n) {
    // use fast exponentiation to calculate x^y % mod
    int mod = 1e9+7;
    auto quickmul = [mod](int x, long long y) -> int {
        int ret = 1, mul = x;
        while (y > 0) {
            if (y % 2 == 1) {
                ret = (long long)ret * mul % mod;
            }
            mul = (long long)mul * mul % mod;
            y /= 2;
        }
        return ret;
    };

    return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
}


int main()
{
    std::cout<<countGoodNumbers(806166225460393);
    // std::cout<<modPow(5,4 );
}