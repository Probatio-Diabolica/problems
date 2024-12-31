/**
 * @file q800.cc
 * @author G__Hearnh(Probatio-Diabolica)
 * @brief 
 * @date 2024-11-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<cmath>
int helpForSakurako()
{
    int l,r;
    std::cin>>l >> r;
    int diff=r-l;
    double temp=(-1 + sqrt(1+8.0*diff))/2.0;
    int ans=(int) temp;
    std::cout<<ans+1<<std::endl;
    return 0;
} 

int main()
{

    int testcase=1;
    std::cin>>testcase;
    while(testcase--)
    {
        helpForSakurako();
    }
    return 0;
}