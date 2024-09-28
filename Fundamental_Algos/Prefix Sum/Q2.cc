#include<iostream>
#include<vector>

std::ostream& operator<<(std::ostream& stream , std::vector<int> vec)
{
    for(int i : vec) stream <<i<<" , ";
    return stream;
}

int minStartValue(std::vector<int>& nums) 
{
    int sum=0,neg=0;
    for(int el:nums)
    {
        sum+=el;
        if(sum<neg) neg=sum;
    }  
    return neg<0 ? -1*(neg-1) : 1;
}


int main()
{
    std::vector<int> a={-3,2,-3,4,2};
    std::vector<int> b={1,-2,-3};
    std::vector<int> c={1,2};
    std::cout<<minStartValue(c)<<"\n";
}