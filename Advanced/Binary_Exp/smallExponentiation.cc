#include<iostream>
const int m=1e9+7;
long long exp(long long num,long long power)
{
    long long res=1;
    // time complexity O(log(power) i.e, number of bits in power)
    while(power>0)
    {
        // std::cout<<++iteration<<"  iteration\n";
        if(power&1) res=(res*num)%m;  
        num=(num*num)%m; //multiplied it by itself
        power>>=1; //devided it by 2 also known as shifting it left by one position
    }
    return res;
}



int main()
{
    std::cout<<exp(2,1500); //worst case
    
}