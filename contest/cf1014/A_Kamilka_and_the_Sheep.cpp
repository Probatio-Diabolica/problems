#include <bits/stdc++.h>


int wot(std::vector<int> &vec)
{
    int sol=0;
    
    return sol;
}

int main()
{
    int t;
    std::cin>>t;

    while(--t > -1)
    {
        int n;
        std::cin>>n;
        std::vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            std::cin>>vec[i];
        }
        std::cout<<wot(vec);
    }
}