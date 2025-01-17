#include"include.hpp"

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int> solution(A.size(),0),hash(A.size(),-1);
    int sum=0;
    for(int i=0;i<A.size();i++)
    {
        sum += (++hash[A[i]-1]) + (++hash[B[i]-1]);
        solution[i]=sum;
    }
    return solution;
}

int main()
{
    iArray x = {7,6,5,4,3,2,1},y={1,2,3,4,5,6,7};

    cout<<findThePrefixCommonArray(x,y);
}