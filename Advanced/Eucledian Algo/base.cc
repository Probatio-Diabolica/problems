#include<iostream>
static int iter=0;

int gcd(int num1,int num2)
{
    std::cout<<"Iter : "<<++iter<<"\n";
    return (num2==0) ? num1 : gcd(num2,num1%num2); 
}

int main()
{
    std::cout<<gcd(29,9000);
}
