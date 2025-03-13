#include <cstddef>
#include <iostream>
#include <vector>

long long ops(std::vector<int>& vec)
{
    long long op=0;

    for(size_t i=1;i<vec.size();i++)
    {
        int temp=0;
        if(vec[i-1] > vec[i])temp=vec[i-1]-vec[i];
        op+=temp;
        vec[i]+=temp;
    }

    return op;
}


int main()
{
    int n;
    std::cin>>n;
    std::vector<int> vec(n);

    for(int i=0;i<n;i++) std::cin>>vec[i]; 

    std::cout<<ops(vec);

}