#include<iostream>
#include<vector>

int totalFruit(std::vector<int>& fruits) 
{
    int e1=fruits[0],e2=fruits[0],maxWindow=0;
    for(size_t left=0;left<fruits.size()-maxWindow;left++)
    {
        int right=left+1;
        int e1=fruits[left],e2=fruits[left];
        int window=1;
        while(right<fruits.size())
        {
            if(fruits[right]!=e1 and e1==e2)
            {
                e2=fruits[right];
            }
            if(fruits[right]==e1 or fruits[right]==e2) window++;
            else break;
            right++;
        }
        maxWindow=maxWindow>window ?  maxWindow : window;
    }
    return maxWindow;        
}

int main()
{
    std::vector<int> a={1,2,1};
    std::vector<int> b={0,1,2,2};
    std::vector<int> c={1,2,3,2,2};
    std::cout<<totalFruit(c);
}