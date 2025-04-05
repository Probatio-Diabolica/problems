#include <iostream>
#include <vector>


std::vector<int> applyPermutation(std::vector<int> sequence, std::vector<int> permutation) {
    std::vector<int> newSequence(sequence.size());
    for(int i = 0; i < sequence.size(); i++) {
        newSequence[i] = sequence[permutation[i]];
    }
    return newSequence;
}

std::vector<int>& permute(std::vector<int>& sequence, std::vector<int>& permutation, long long k)
{
    while (k > 0) {
        if (k & 1) {
            sequence = applyPermutation(sequence, permutation);
        }
        permutation = applyPermutation(permutation, permutation);
        k >>= 1;
    }
    return sequence;
}

template <typename T>
std::ostream& operator <<(std::ostream& stream,std::vector<T>& v)
{
    for(T &i:v) stream<<i<<" ";
    stream<<'\n';
    return stream;
}


int main()
{
    int N , K;
    std::cin>>N >> K;
    std::vector<int> A(N),B(N);
    for(int i=0;i<N;i++) std::cin>>A[i];
    for(int i=0;i<N;i++) std::cin>>B[i];

    std::cout<<permute(A, B,K);
}