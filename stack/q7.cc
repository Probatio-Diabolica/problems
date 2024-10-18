#include<iostream>
#include<vector> 
#define pos int 
#define spd int

void swap(std::pair<pos,spd> *a,std::pair<pos,spd>*b)
{
   std::pair<pos,spd> temp=*a;
    *a = *b;
    *b=temp;
}

int part(std::vector<std::pair<pos,spd>> &vec,int head,int tail)
{
    int pivot=vec[head].first;
    int index=head;
    for(int i=head+1;i<=tail;i++){
        if(pivot<vec[i].first)
        {
            index++;
            swap(&vec[i],&vec[index]);
        }
    }
    swap(&vec[index],&vec[head]);
    return index;
}

void QS(std::vector<std::pair<pos,spd>> &vec,int head,int tail)
{
    if(head<tail)
    {
        int partition=part(vec,head,tail);
        QS(vec,head,partition-1);
        QS(vec,partition+1,tail);
    }
}

int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) 
{
    std::vector<std::pair<pos,spd>> map(speed.size());
    for(int i=0;i<speed.size();i++)
    {
        map[i].first=position[i];
        map[i].second=speed[i];
    }
    QS(map,0,speed.size()-1);

    int fleet=0,curr_time=0;
    
    for (int i = 0; i < speed.size(); i++)
    {
        int dis_time=(target-map[i].first)/map[i].second;
        if(curr_time<dis_time) 
        {
            ++fleet;
            curr_time=dis_time;
        }
    }
    
    return fleet;
}



int main()
{
    std::vector<int> posi={10,8,0,5,3},spdd={2,4,1,1,3};
    int target=12;

    std::cout<<carFleet(target,posi,spdd);
}