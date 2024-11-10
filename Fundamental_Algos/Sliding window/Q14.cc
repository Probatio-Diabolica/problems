#include<iostream>
#include<vector>

int minimumCardPickup(std::vector<int>& cards) 
{
    int deckSize,right=0,minWindow=cards.size(),validWindow=0;
    for(size_t current=0;current<cards.size()-1;current++)
    {
        deckSize=1;
        right = current+1;
        // std::cout<<"------------------------------------------------------------------\n";
        while((right <= (minWindow+right))and (right<cards.size())) //error at 12 with right < mnwindow
        {
            deckSize++;
            // std::cout<<cards[current]<<" " <<cards[right]<<"\n";
            if(cards[current]==cards[right])
            {
                validWindow = deckSize;
                minWindow=minWindow < validWindow ? minWindow : validWindow;
                // std::cout<<cards[current]<<" Equals "<< cards[right]<<" minWindow" <<minWindow <<" - validW "<<validWindow<<"\n";

                break;
            }
            right++;
        }
        
    }
    return (minWindow > 0 ) and (minWindow!=cards.size()) ? minWindow : -1;

}

int main()
{
    std::vector<int> a={3,4,2,3,4,7};
    std::vector<int> b={1,0,5,3};
    std::vector<int> c ={95,11,8,65,5,86,30,27,30,73,15,91,30,7,37,26,55,76,60,43,36,85,47,96,6};
    std::vector<int> d={77,10,11,51,69,83,33,94,0,42,86,41,65,40,72,8,53,31,43,22,9,94,45,80,40,0,84,34,76,28,7,79,80,93,20,82,36,74,82,89,74,77,27,54,44,93,98,44,39,74,36,9,22,57,70,98,19,68,33,68,49,86,20,50,43};
    
    // std::cout<<minimumCardPickup(a)<<"\n";
    // std::cout<<minimumCardPickup(c)<<"\n";  
    // std::cout<<minimumCardPickup(b)<<"\n";
    // std::cout<<minimumCardPickup(d)<<"\n";
    std::cout<<__cplusplus;
}