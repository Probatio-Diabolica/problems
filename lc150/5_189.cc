#include"include.hpp"

void swap(int * a, int * b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void reverse(vector<int>& nums,int head,int tail)
{
    int size=(tail-head) ;
    for(int i=0;i<=((size)/2);i++)
    {
        swap(&nums[i+head],&nums[tail-i]);
    }
}

void rotate(vector<int>& nums, int k) {
    k=k%nums.size();
    if(nums.size()==1 or k==0) return;
    int size=nums.size()-1;
    reverse(nums,0,size);
    reverse(nums,0,k-1);
    reverse(nums,k,size);
}

int main()
{
    iArray a={1,2,3,4,5,6,7};

    // reverse(a,0,a.size()-1);
    rotate(a,1);
    std::cout<<a;
}