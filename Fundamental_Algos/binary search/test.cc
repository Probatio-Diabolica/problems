#include<iostream>
#include<vector>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

int bs(std::vector<int> &vec,int head,int tail,int target)
{
    int mid=head +(tail-head)/2;
    if(head<=tail)
    {
        if(vec[mid]==target) return mid;
        else if(vec[mid]>target) bs(vec,head,mid-1,target);
        else bs(vec,mid+1,tail,target);
    }
    else return -1;
    // return -1;
}

#pragma GCC diagnostic pop



int main()
{
    std::vector<int> a={1,2,3,4,5,6};
    std::cout<<bs(a,0,a.size(),3)<<"\n";
}