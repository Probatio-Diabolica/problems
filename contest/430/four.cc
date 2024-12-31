#include<iostream>

int comb(int n,int k)
{
    if (k<0 or k>n) return 0;
    if  (k>(n/2)) k=n-k;
    int result =1;
    for(int i =0;i<k;i++)
    {
        result*=(n-i);
        result/=(i+1);
    }
    return result;
}

int power(int num,int exp)
{
    int sol=1;
    while(exp>0)
    {
        if(num&1) sol*=num;
        num*=num;
        exp>>=1;
    }
    return sol;
}

int countGoodArrays(int n, int m, int k) {
    return ( comb(n-1,n-k-1)* (m*power((m-1),(n-k-1)) ) ) % 1000000007;
}

int main()
{
    using std::cout;
    cout<<countGoodArrays(3,2,1)<<"\n";
    cout<<countGoodArrays(4,2,2)<<"\n";
    cout<<countGoodArrays(5,2,0)<<"\n";
}