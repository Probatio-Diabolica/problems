#include<iostream>
#include <vector>



int std_count(std::vector<int>& books, int page)
{
    int kidz =1;
    int sum=0;
    for(int i :books)
    {
        if((sum + i) > page)
        {
            ++kidz;
            sum=0;    
        } 
        sum+=i;
    }
    return kidz;
}

int findPages(std::vector<int>& arr, int n, int m) {
    int head=0, tail=0;
    if(n<m) return -1;
    for(int i:arr)
    {
        tail+=i;
        if(i > head) head=i;
    }

    while(head<=tail)
    {
        int mid = head + (tail-head) /2;
        if( std_count(arr, mid)> m)
        {
            head = mid+1; 
        }
        else 
        {
            tail = mid - 1;
        }
    }
    return head;
}



int main()
{
    std::vector<int> x{25,46,28,49,24};
    std::cout<<findPages(x, 5, 4);
}
