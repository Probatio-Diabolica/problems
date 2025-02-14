#include<iostream>
const int m=1e9+7;


int padovanSequence(int n) {
    if(n<3) return 1;
    int l=padovanSequence(n-2);
    int r=padovanSequence(n-3);    
    return (l+r)%m;
}


int main()
{
    std::cout<<padovanSequence(100000);
}