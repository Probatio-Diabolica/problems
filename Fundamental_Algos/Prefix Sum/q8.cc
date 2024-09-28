#include"includes.hpp"

void swap(int* a, int* b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
    // *a^=*b;
    // *b^=*a;
    // *a^=*b;
}
int partition(std::vector<int>& vec,int head,int tail)
{
    int pivot=vec[head];
    int index=head;
    for(int current = head+1;current<=tail;current++)
    {
        if(vec[current]<pivot)    swap(&vec[++index],&vec[current]);
    }
    swap(&vec[index],&vec[head]);
    return index;
}

void QS(std::vector<int>& vec,int head,int tail)
{
    if(head<tail)
    {
        int pivot=partition(vec,head,tail);
        QS(vec,head,pivot-1);
        QS(vec,pivot+1,tail);
    }
}

int bs(int arr[],int head,int tail,int target)
{
    int mid = head+(tail-head)/2,value=0;

    while(head<=tail)
    {
        if(arr[mid]==target)
        {
            return mid+1;
        }
        else if(arr[mid]>target)
        {
            value=mid;
            tail=mid-1;
        }
        else
        {
            value=mid+1;
            head=mid+1;
        }
        mid=head + (tail - head) / 2;
    }
    return value;
}

std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries) {
    int sums[nums.size()],sum=0;
    std::vector<int> sol;
    QS(nums,0,nums.size()-1);
    for(int i =0;i<nums.size();i++)
    {
        sum+=nums[i];
        sums[i]=sum;
    }
    for (int i:queries) sol.push_back(bs(sums,0,nums.size()-1,i));
    return sol;
}






int main()
{
    std::vector<int> a={4,5,2,1}, b={3,10,21},c={2,3,4,5},d={1};
    std::cout<<answerQueries(a,b)<<"\n";
    std::cout<<answerQueries(c,d)<<"\n";
}