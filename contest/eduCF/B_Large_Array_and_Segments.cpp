#include<iostream>
#include <vector>

int solution(std::vector<unsigned int>& b,int lim)
{
    int r=0;
    unsigned long long sum=0;
    while(sum<lim and r<b.size())
    {
        sum+=b[r];
        ++r;
    }
    int offSet=0;
    if((sum < lim) and (r == b.size())) return 0;
    else if((sum >= lim) and (r == b.size())) return 1;
    else return (b.size()-r) +1 ; 
    
}

int main()
{
    int t,n,k;
    unsigned long long x;
    std::cin>>t;
    while(--t>-1)
    {
        std::cin>>n>>k>>x;
        std::vector<unsigned int> a(n),b(n*k);
        for(int i=0;i<n;i++)
        {
            std::cin>>a[i];
        }
        for(int  i =0;i<b.size();i++)
        {
            b[i]=a[i%a.size()];
        }
        std::cout<<solution(b, x)<<'\n';
    }
}