#include<iostream>

void win(int n,int del,bool& sol)
{
    if (n<0 or del<1)
    {
        return;
    }
    if(!(del&1) and n<del) sol=false;
    win(n-del,del-1,sol);
}
bool canAliceWin(int n) 
{
    if(n<10) return false;
    else if(n==10) return true;
    bool sol=true;
    win(n,10,sol);
    return sol;
}

int main()
{
    // int i=12;
    for(int i=10;i<51;i++)
    {
        std::cout<<i<<" :: "<<canAliceWin(i)<<"\n";
    }
    
}

