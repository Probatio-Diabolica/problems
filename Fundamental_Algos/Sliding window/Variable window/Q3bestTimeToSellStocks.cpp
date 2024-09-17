#include<iostream>
#include<vector>




int maxProfit(std::vector<int>& prices) 
{
    int current=0,max=0;
    for(size_t future=0;future<prices.size();future++)
    {
        if(prices[current]<prices[future] && (prices[future]-prices[current]) > max) max=(prices[future]-prices[current]);
        if(prices[future] < prices[current]) current=future;
    }
    return max;
}



int main()
{
    std::vector<int> a={7,1,5,3,6,4};
    std::vector<int> b={2,1,2,3,1,2,7,8,6,1};
    std::vector<int> c={1,2,3,4,5,6};
    std::vector<int> d={9,8,7,6,5};

    std::cout<<maxProfit(a)<<"\n";
    std::cout<<maxProfit(b)<<"\n";
    std::cout<<maxProfit(c)<<"\n";
    std::cout<<maxProfit(d)<<"\n";
    // std::cout<<maxProfit(a)<<"\n";
    // std::cout<<maxProfit(a)<<"\n";
}