#include<iostream>

int main()
{
    int i =1,n=10,sum=0;
    // begin:if(i>n)goto end;
    // sum+=i;
    // std::cout<<"lets see\n";
    // i++;
    // goto begin;
    // end:std::cout<<"Sum == " <<sum; 

    while(i<n)
    {
        sum+=i;
        i++;
    }
    std::cout<<sum;

}