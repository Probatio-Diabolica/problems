#include<iostream>
#include <climits>

int reverse2(int x) {
    int ans=0;
    while(x!=0)
    {
        int digit=x%10;
        if((ans>INT_MAX/10) or (ans<INT_MIN/10)) return 0;
        ans=(ans*10) + digit;
        x/=10;
    }
    return ans;
}

 int reverse(int x) {
        int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x
            
            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            
            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10; // Remove the last digit from x
        }
        return ans; // Return the reversed number
    }

int main()
{
    std::cout<<reverse2(-121)<<"\n";
    std::cout<<reverse2(1534236469)<<"\n";
    
}