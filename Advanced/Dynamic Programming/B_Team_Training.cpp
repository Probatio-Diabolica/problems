#include<iostream>
#include <vector>







int main()
{
    int t,n,x;
    std::cin>>t;
    while(--t>-1)
    {
        std::cin>>n >> x;
        std::vector<int> student(n);
        for(int i =0;i<n;i++)
        {
            std::cin>>student[i];
        }
        
    }
}