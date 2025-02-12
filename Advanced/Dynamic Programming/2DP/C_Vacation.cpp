// #include"includes.hpp"

#include<iostream>
#include<vector>

int max(int a, int b, int c)
{
    return (a>b and a>c) ? a : (b>c) ? b: c;  
}

int max(int a, int b)
{
    return a>b ? a : b;
}

int vacation(std::vector<std::vector<int>>& possActivities, int activity,int currDay,std::vector<std::vector<int>>& states)
{
    if(currDay > possActivities.size()-1) return 0;
    if(states[currDay][activity]!=-1) return states[currDay][activity];
    int maxi;    
    
    if(activity==0)
    {
        maxi = max(vacation(possActivities,1,currDay+1,states),vacation(possActivities,2,currDay+1,states)) +possActivities[currDay][activity];
    }
    
    else if(activity==1)
    {
        maxi = max(vacation(possActivities,0,currDay+1,states),vacation(possActivities,2,currDay+1,states)) +possActivities[currDay][activity];
    }
    
    else{
        maxi = max(vacation(possActivities,0,currDay+1,states),vacation(possActivities,1,currDay+1,states)) + possActivities[currDay][activity];
    }

    return states[currDay][activity]=maxi;
}

int main()
{
    int days;
    std::cin>>days;
    std::vector<std::vector<int>> possActivities(days,std::vector<int>(3,0)),states(days,std::vector<int>(3,-1));
    for(int i=0;i<days;i++)
    {
        for(int j =0 ; j <3;j++)
        {
            std::cin>>possActivities[i][j];
        }
    }
    std::cout<< max(vacation(possActivities,0,0,states),vacation(possActivities,1,0,states),vacation(possActivities,2,0,states));
}