#include<iostream>
#include<vector>

template<typename T>
void printarr(std::vector<T>& v)
{
    for(auto i:v) std::cout<<i<<" , ";
}
std::vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
    std::vector<int> negs={};    
    std::vector<long long> sol={};                                             
    for(int i=0;i<K;i++)
    {
        if(A[i]<0) negs.push_back(A[i]);
    }
     sol.push_back(negs.empty()? 0 : negs[0]);
    for(int i=1;i<N-K+1;i++)
    {
        if(A[i-1]<0) 
        {
            if(negs.size()>1) negs.erase(negs.begin());
            else negs.clear();
        }
        if(A[i+K-1]<0) negs.push_back(A[i+K-1]);
        sol.push_back(negs.empty()? 0 : negs[0]);
    }
    return sol;
}


int main()
{
    long long int A[]={48, 974 ,5, -59 ,-451};
    long long int B[]={12 ,-1 ,-7 ,8 ,-15 ,30 ,16, 28};
    printFirstNegativeInteger(A,5,3);
    std::cout<<"\n";
    printFirstNegativeInteger(B,8,3);
}