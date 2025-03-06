#include<iostream>

int main()
{
    int count=0;
    for(int i=0;i<10;i++)
    {
        count+= (i&1);
        std::cout<<"i-> "<<i <<" |Count -> "<<count<<"\n";
    }
    
}