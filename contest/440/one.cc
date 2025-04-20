#include"include.hpp"


int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
{
    int unplaced=0;
    for(int fruit:fruits)
    {
        bool placed = false;
        for(int i=0;i<baskets.size();i++)
        {
            if(baskets[i]>=fruit)
            {
                baskets[i]=0;
                placed = true;
                break;
            }
        }
        if(!placed) ++unplaced;
    }
    return unplaced;        
}

int main()
{
    iArray fr{4,2,5},ba{3,5,4};
    std::cout<<numOfUnplacedFruits(fr, ba);
}