#include"includes.hpp"
#define forLoopNeg(x,y) for (int i = x; i > y; i--)


std::string shiftingLetters(std::string s, std::vector<int>& shifts) 
{
    int sum=0;
    char con;
    forLoopNeg(shifts.size()-1,0)
    {
        // Maths
        sum+=shifts[i];
        sum%=26;
        // Letters
        int end='z'- s[i];
        if(sum>end)
        {
            con='a'+(sum-end)-1;
            s[i]=con;
        }else s[i]+=sum;        
    }
    return s;
}

int main()
{
    std::string x="ruu";
    std::vector<int> a={26,9,17};
    std::cout<<shiftingLetters(x,a);
}