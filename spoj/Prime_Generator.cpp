#include<iostream>
#include<vector>
void primes(int start, int end)
{
    std::vector<bool> seive(end+1, true);
    seive[0] = false;
    seive[1] = false;

    for(int i = 2 ; i<end;i++)
    {
        
    }

    for(int i = 0 ; i <seive.size();i++)
    {
        if(seive[i] == true) std::cout<<i + start<<'\n';
    }
}

int main()
{
    int t ;
    int start, end;

    std::cin>>t;
    while(--t > -1)
    {
        std::cin>>start>>end;        
        primes(start,end);
        std::cout<<'\n';
    }
}