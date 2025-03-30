#include <ios>
#include <iostream>
#include <vector>

int eq(std::vector<int> &M,std::vector<int> &N)
{
    int n = M.size();
    
    int diff=0;
    for(int i =0;i<n-1;i++)
    {
        if(M[i] > N[i+1]) diff+= M[i] - N[i+1];
    }
    return diff + M[n-1];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin>>t;
    int n;
    while(--t>-1)
    {
        std::cin>>n;
        std::vector<int> a(n), b(n);
        for(int i =0;i<n;i++)
        {
            std::cin>>a[i];
        }
        for(int i =0;i<n;i++)
        {
            std::cin>>b[i];
        }
        std::cout<<eq(a,b)<<'\n';
    }
}