#include<iostream>
#include<vector>

using namespace std;



void swap(int & a, int & b)
{
    int temp=a;
    a=b;
    b=temp;
}


int partition(vector<int>& vec,int head, int tail)
{
    int index=head;
    int pivot=vec[head];
    for(int i=head+1;i<=tail;i++)
    {
        if(vec[i] < pivot)
        {
            ++index;
            swap(vec[i],vec[index]);
        }
    }
    swap(vec[index],vec[head]);
    return index;
}


void QS(vector<int>& vec, int head, int tail)
{
    if(head<tail)
    {
        int part=partition(vec,head,tail);
        QS(vec,head,part-1);
        QS(vec,part-1,tail);
    }
}


long long maxScore(vector<int>& nums) 
{
    typedef long long ll;
    ll sol;
    QS(nums,0,nums.size()-1);


    
    

    return sol;
}

int main()
{
    vector<int> x={2,4,6,8};
    std::cout<<maxScore(x);
}
