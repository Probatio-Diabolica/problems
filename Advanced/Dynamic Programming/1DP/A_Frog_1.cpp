#include<iostream>
#include<vector>
#include<cstdint>


std::vector<int> memo(1e5+1,-1);

// O(1)
int min(int a, int b , int c)
{
    int x = (a> b) ? b:a;
    int y = (b > c) ? c : b;
    return (x > y) ? y : x;
}

// Memoized DP O(N)
int Jump(std::vector<int>& rocks,int position,int cost)
{
    if(position==0) return 0;

    if(memo[position]!=-1) return memo[position];
    
    int leftTree=Jump(rocks,position-1,cost)+ std::abs(rocks[position]-rocks[position-1]);
    
    int rightTree=INT32_MAX;
    
    if(position>1)rightTree = Jump(rocks,position-2,cost)+ std::abs(rocks[position]-rocks[position-2]);
    
    cost = min(cost,leftTree,rightTree);

    return memo[position]=cost;
}




int main()
{
    int N;
    std::cin>>N;
    std::vector<int> vec(N),memo(N,-1);
    int i=-1;
    while(N)
    {
        std::cin>>vec[++i];
        --N;
    }
    std::cout<<Jump(vec,vec.size()-1,INT32_MAX);

}