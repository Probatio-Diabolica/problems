#include<iostream>
#include<vector>

std::ostream& operator<<(std::ostream& stream,std::vector<int>& vec)
{
    for(int i=0;i<vec.size();i++) stream<<vec[i]<<" , ";
    return stream;
}

void swap(int* a, int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(std::vector<int> &vec,int head,int tail)
{
    int index=head;
    int pivot=vec[head];
    for(int i=head+1;i<=tail;i++)
    {
        if(pivot<vec[i])
        {
            index++;
            swap(&vec[i],&vec[index]);
        }
    }
    swap(&vec[index],&vec[head]);
    return index;
}

void QS(std::vector<int> &vec,int head,int tail)
{
    if(head<tail)
    {
        int pivot=partition(vec,head,tail);
        QS(vec,head,pivot-1);
        QS(vec,pivot+1,tail);
    }
}

int maxProfit2(int k,std::vector<int>& prices) 
{
    int ans=0,maxProfit=0;
        std::vector<int> profit={};
        int left=0,right=0;
        while(right<prices.size())
        {
            if(prices[left]<prices[right])
        {
            if(maxProfit<prices[right]-prices[left])
            {
                maxProfit=prices[right]-prices[left];
            }
            
        }
        if((prices[left]>prices[right]) or right==prices.size()-1)
        {
            left = right;
            profit.push_back(maxProfit);
            maxProfit=0;
        }
        ++right;
        }

        QS(profit,0,profit.size()-1);

        for(int i=0;i<k and i<profit.size();i++) ans+=profit[i];

        return ans;


}

int maxProfit(int k,std::vector<int>& prices)
{
    int ans=0,maxProfit=0;
    std::vector<int> profit={};
    int left=0,right;
    while(left<prices.size())
    {
        int rightMaxIndex=0;
        right=left;
        while (right<prices.size())
        {
            
            if(prices[rightMaxIndex]<prices[right]) rightMaxIndex=right;
            ++right;
        }

        
    }
}
int main()
{
    std::vector<int> a={3,2,6,5,0,3};
    std::vector<int> b={1,2,4};
    std::vector<int> c ={7,4,9,7,2,9,0,5,9};
    std::vector<int> d={6,1,3,2,4,7};
    std::cout<<maxProfit(2,a)<<"\n";
    std::cout<<maxProfit(2,b)<<"\n";
    std::cout<<maxProfit(2,c)<<"\n";
    std::cout<<maxProfit(2,d);
}