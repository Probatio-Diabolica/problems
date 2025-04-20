#include<iostream>


int main()
{
    int t ;
    std::cin>> t;

    while(--t>-1)
    {
        int x;
        std::cin>>x;
        std::string a , b;
        std::cin>>a>>b;

        int  odd0 = 0 ,even0=0 , ones=0;

        for(int i =0;i<x;i++)
        {
            if(a[i]=='1') ++ones;
            if(i&1) //odd
            {
                if(a[i]=='1') 
                {
                    
                }
                else 
                {
                    ++odd0;
                }

                if(b[i]=='1') 
                {

                }
                else 
                {

                }
            }
            else //even
            {
                if(a[i]=='1') 
                {

                }
                else 
                {
                    ++odd0;
                }

                if(b[i]=='1') 
                {

                }
                else 
                {

                }
            }
        }

        if(p0>=p1 and q0>=q1) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }
}