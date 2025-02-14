#include"includes.hpp"



int solution(int n,std::vector<int>& states)
{
    if(n<=1) return n;
    if(states[n]!=-1) return states[n];
    int answer= solution(n-2,states) + solution(n-1,states);
    return states[n] = answer;
}

int fib(int n)
{
    std::vector<int> states(n+5,-1);
    return solution(n,states); 
}

int fib2(int n)
{
    if(n<=1) return n;
    iArray x(n+1,0);
    x[1]=1;
    // std::cout<<x<<'\n';
    for(int i=2;i<=n;i++)
    {
        x[i] = x[i-1] + x[i-2];

    }
    return x[n];
}

int fib3(int n)
{
    if(n<=1) return n;
    int l1=0,l2=1;
    int l3;
    for(int i =2;i<=n;i++)
    {
        l3=l1+l2;
        l1=l2;
        l2=l3;
    }
    return l3;
}

int main()
{
    cout<<fib3(4);
}
