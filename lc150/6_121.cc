#include "include.hpp"

int maxProfit(vector<int>& prices) 
{
    int profit=0;
    for(int r=1 , l=0;r<prices.size();r++)
    {
        if(prices[l]>prices[r]) l=r;
        else if(prices[l]<prices[r])
        {
            if(profit < (prices[r] - prices[l])) profit= prices[r] - prices[l];
        }
    }        
    return profit;
}


int main(){
    iArray arr={7,6,4,3,1};
    std::cout<<maxProfit(arr);
}