#include<iostream>


int main()
{
    int num=0;
    std::cin>>num;
    int res=0;
    while(num>0)
    {
        int temp=num%10;
        num/=10;
        if(temp) ++res;
    }
    std::cout<<res;
}