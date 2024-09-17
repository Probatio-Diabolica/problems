#include<iostream>
#include<climits>

int reverse(int x)
{
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

bool isPalindrome(int x) 
{
    if(x<0)return false;
    return (x!=reverse(x)) ? false:true;
}

int main()
{
    std::cout<<isPalindrome(292);
    std::cout<<isPalindrome(-121);
}