#include <iostream>
#include <vector>


int main()
{
    int n;
    std::cin>>n;
    std::vector<int> sub(n+1);
    for(int i=0;i<n-1;i++)
    {
        int num;
        std::cin>>num;
        sub[num]=1;
    } 

    for(int i =1;i<n+1;i++)
    {
    if(!sub[i]) std::cout<<i;
    }
}