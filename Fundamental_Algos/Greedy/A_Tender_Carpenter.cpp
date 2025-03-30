#include<iostream>
#include <vector>


bool cog()
{
    return false;
}

int main()
{
    int t;
    std::cin>>t;
    while(--t >-1)
    {
        int n ;
        std::cin>>n;
        std::vector<int> arr(n);
        for(int i =0;i<n;i++)
        {
            std::cin>>arr[i];
        }

        std::cout<< ((t>3) ? "YES\n" : "NO\n") ;
    }
}
