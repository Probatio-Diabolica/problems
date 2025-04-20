#include <climits>
#include <cstdint>
#include <iostream>


long long divide(int dividend, int divisor) {
    if(dividend == divisor)
        return 1;
    bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
    int a    = abs(dividend);
    int b = abs(divisor);
    int ans = 0;
    while(a >= b){  // while dividend is greater than or equal to divisor
        short q = 0;
        while(a > (b<<(q+1)))
            q++;
        ans += (1<<q);  // add the power of 2 found to the answer
        a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
    }
    if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
        return INT_MAX;
    return isPositive ? ans : -ans;
}

int main()
{
    std::cout<<divide(-2147483648,-1 );
}