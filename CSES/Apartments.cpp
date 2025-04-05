#include <cstddef>
#include <iostream>
#include <queue>

long long sol(std::priority_queue<long long>& people,std::priority_queue<long long>& sizes,size_t diff)
{
    long long fit = 0;
    // std::cout<<people.size();
    while(!people.empty() and !sizes.empty())
    {
        int desire = people.top();
        int reality = sizes.top();
        int current_diff = std::abs(reality-desire); 
        if( current_diff <= diff)
        {
            people.pop();
            sizes.pop();
            ++fit;
        }
        else
        {
            desire > reality ? people.pop() : sizes.pop() ;
        }
    }
    return fit;
}



int main()
{
    size_t people, apartmets ,maximum;
    std::cin>>people>>apartmets>>maximum;

    std::priority_queue<long long> maxPeople, maxDesires;
    
    // desires of thoses bastards
    for(size_t i = 0; i<people; i++)
    {
        long long desire;
        std::cin>>desire;
        maxPeople.push(desire);
    }
    // actual reality. Yeah, hit'em with a hammer
    for(size_t i = 0; i<apartmets; i++)
    {
        long long reality;
        std::cin>>reality;
        maxDesires.push(reality);
    }
    
    std::cout<<sol(maxPeople,maxDesires,maximum);
}