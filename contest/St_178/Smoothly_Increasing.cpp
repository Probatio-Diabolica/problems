#include "include.hpp"
using namespace std;

void solve(vector<int>& vec)
{
    
    for(int i=0;i<vec.size();i++)
    {

    }
}

int main() {

    int T,N;
    std::cin>>T;
    while(T>0)
    {
        std::cin>>N;
        std::vector<int> vec(N);
        for(int i=0;i<N;i++)
        {
            std::cin>>vec[i];
        }
        solve(vec);

        --T;
    }
}
