#include"include.hpp"


bool doesValidArrayExist(vector<int>& derived) 
{
    int solution=0;
    for(int i : derived)
    {
        solution ^= i;
    }
    return solution==0;
}


int main()
{
    iArray x={1,1,0};
    std::cout<<doesValidArrayExist(x);
}