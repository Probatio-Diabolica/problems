#include<iostream>

//binary multiplication
const long long m=INT32_MAX;

//This is used when the two numbers are very huge such that their multiplication leads to overflow
long long binMultiply(long long a, long long b)
{
    long long res=0;
    //Log^2 (N)
    while(b>0)
    {
        if(b&1) res=(res + a) % m;
        a=(a+a)%m;
        b>>=1;
    }
    // std::cout<<iterations<<"\n";
    return res;
}

int pow(long long num,long long power)
{
    int res=1;
    while(power>0)
    {
        if(power&1) res=binMultiply(res,num);
        num=binMultiply(num,num);
        power>>=1;
    }
    return res;
}
int main()
{
    std::cout<<pow(2,10000);
}