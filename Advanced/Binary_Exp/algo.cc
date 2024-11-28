#include<iostream>
long long exp(int num,long long ex)
{
    long long res=1,iteration=0;
    while(ex>0)
    {
        std::cout<<++iteration<<"  iteration\n";
        if(ex&1) res*=num;  
        num*=num; //multiplied it by itself
        ex>>=1; //devided it by 2
        
    }
    return res;
}



int main()
{
    std::cout<<exp(1,1000000000000); //worst case
    
}