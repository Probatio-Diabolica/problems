#include "sol.h"
int maint(){
    std::vector<int> a={1,2,2,1,1,3};
    std::vector<int> b={-3,0,1,-3,1,1,1,-3,10,0};
    std::vector<int> c={1,2};
    std::vector<int> d={1};
    
    
    Solution sol;
    std::cout<<sol.uniqueOccurrences(a)<<std::endl;
    std::cout<<sol.uniqueOccurrences(b)<<std::endl;
    std::cout<<sol.uniqueOccurrences(c)<<std::endl;
    std::cout<<sol.uniqueOccurrences(d)<<std::endl;
    //std::cout<<;
    return 0;
}

int main()
{
    std::unordered_map<int,int> a;
    a[0]=90;
    a[1]++;
    std::cout<<a[1];
    
    return 0;
}