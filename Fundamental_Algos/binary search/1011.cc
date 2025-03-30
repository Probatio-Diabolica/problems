#include<iostream>
#include <vector>

int returnDays(std::vector<int>& weights, int cap)
{
    int current =0,day =0;
    for(int i =0;i<weights.size();i++)
    {
        if(current+weights[i] <= cap) current +=weights[i];
        else 
        {
            ++day;
            current =weights[i];
        }
    }
    return day;
}

int shipWithinDays(std::vector<int>& weights, int days) 
{
    int head=0,tail=0;
    for(int i:weights)
    {
        tail+=i;
        if(i>head) head=i;
    }

    while(head<=tail)
    {
        int mid = head+(tail-head)/2;

        if(returnDays(weights,mid) >= days) head = mid+1;
        else tail=mid-1;
    
    }
    return head;
}

int main()
{
    std::vector<int> v{1,2,3,1,1},u{3,2,2,4,1,4};
    std::cout<<shipWithinDays(v, 4);
}