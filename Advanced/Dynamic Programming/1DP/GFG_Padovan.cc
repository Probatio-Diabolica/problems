#include<iostream>

constexpr int M=1e9+7;

int padovanSequence(int n) {
    int PrevMinusOne = 1, prev = 1, now = 1, Next = 1;

    for (int i=3; i<=n; i++)
    {
        Next = (PrevMinusOne + prev)%M;
        PrevMinusOne = prev;
        prev = now;
        now = Next;
    }

    return Next;    
}

int main()
{

    std::cout<<padovanSequence(1000000);
}