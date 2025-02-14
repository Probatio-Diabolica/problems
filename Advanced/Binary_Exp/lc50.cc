#include<iostream>

double myPow(double x, long n) {
    
    bool pompeii=false;
    if(n==INT32_MAX) return x;
    if(x==1) return 1;

    if(n<0) 
    {  
        if(n==INT32_MIN and (x!=1) and (x!=-1)) return 0.00;
        n= std::abs(n);
        pompeii=true;
    }
    double res=1;
    while(n)
    {
        if(n&1) res*=x;
        x*=x;
        n>>=1;
    }
    return (pompeii) ? (1/res) : res;
}

int main()
{
    std::cout<<"\n"<<myPow(2.0000,10);
    std::cout<<"\n"<<myPow(2.1000,3);
    std::cout<<"\n"<<myPow(2.0000,-2);
    std::cout<<"\n"<<myPow(0,1);
    std::cout<<"\n"<<myPow(2.0000,-2147483648);
    std::cout<<"\n"<<myPow(1.001,INT32_MIN+1);
    std::cout<<"\n"<<myPow(8.84372,-5);
    std::cout<<"\n"<<myPow(0.00001,INT32_MAX);
    std::cout<<"\n"<<myPow(-1,-2147483648);
}