#include<iostream>
#include<vector>



int maxScore(std::vector<int>& cardPoints, int k) 
{
    int head=0,tail=cardPoints.size()-1,sum=0,maxSum=0;
    while(head<k)
    {
        sum+=cardPoints[head];
        head++;
    }
    maxSum=sum;
    while(k!=0)
    {

        sum += (cardPoints[tail--] - cardPoints[--head]);
        maxSum = (maxSum > sum) ? maxSum : sum;
        k--;
    }
    return maxSum;
}

int main()
{
    std::vector<int> a={9,2,2,2,5,4,4};
    std::vector<int> b={1,2,3,4,5,6,1};
    std::vector<int> c={11,49,100,20,86,29,72};
    std::cout<<maxScore(a,3)<<"\n";
    std::cout<<maxScore(b,3)<<"\n";
    std::cout<<maxScore(c,4)<<"\n";

}