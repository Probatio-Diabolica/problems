#include "includes.hpp"

// approach1 sliding window
int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) 
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int realSum=0,bigO=0,odditiy=0;

    for(int i=0;i<minutes and i <customers.size();i++)
    {
        if(grumpy[i]==0) realSum+=customers[i];
        else odditiy+=customers[i];
    }
    if (minutes==customers.size()) return realSum+odditiy;
    bigO=odditiy;
    for(int i=1;i<=customers.size()-minutes;i++)
    {
        if(grumpy[i-1]==1) odditiy-=customers[i-1];
        if(grumpy[i+minutes-1]==1) odditiy+=customers[i+minutes-1];
        else realSum+=customers[i+minutes-1];
        if(odditiy>bigO) bigO=odditiy;
    }
    return realSum+bigO;
}

// app 2 : prefix sum
int maxSatisfied2(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
    int n = grumpy.size() ;
    std::vector<int> psum1(n + 1) , psum2(n + 2) ;
    for(int i = 0 ; i <= n - 1 ; i++){
        psum1[i + 1] = psum1[i] ;
        if(grumpy[i] == 0){
            psum1[i + 1] += customers[i] ;
        }
        psum2[i + 1] = psum2[i] + customers[i] ;
    }
    int ans = psum1[n] ;
    for(int i = 0 ; i + minutes - 1 <= n - 1 ; i++){
        int sum = psum1[i] + (psum2[i + minutes] - psum2[i]) + psum1[n] - psum1[i + minutes] ;
        if(ans<sum)ans = sum;
    }
    return ans ;
}

int main()
{
    std::pair<std::vector<int>,std::vector<int>> a={{1,0,1,2,1,1,7,5},{0,1,0,1,0,1,0,1}};
    std::pair<std::vector<int>,std::vector<int>> b={{1},{1}};
    std::pair<std::vector<int>,std::vector<int>> c={{1,3,4,5,6,4,3,2},{0,1,0,1,0,1,0,1}};
    std::pair<std::vector<int>,std::vector<int>> d={{8,9,2,1,2,0,9,2},{0,1,0,1,0,1,0,1}};

    std::cout<<maxSatisfied(a.first,a.second,3)<<"\n";
    std::cout<<maxSatisfied(b.first,b.second,1)<<"\n";
    std::cout<<maxSatisfied(c.first,c.second,3)<<"\n";
    std::cout<<maxSatisfied(d.first,d.second,3)<<"\n";
}