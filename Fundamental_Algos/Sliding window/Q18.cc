#include<iostream>
#include<vector>

// https://leetcode.com/problems/find-k-closest-elements/description/?envType=problem-list-v2&envId=sliding-window
int bs(std::vector<int>& nums,int target)
{
    int head=0,tail=nums.size()-1,mid= head + (tail - head) / 2;
    while(head<tail)
    {
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) tail=mid-1;
        else head=mid+1;
        mid=head + (tail - head) / 2;
    }
    return mid-1;
}

std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) 
{
    int search=bs(arr,x);
    int poles= (search==0) ? -1 : (search)-k;
    std::vector<int> solution={};
    int left=search,right=search;
    std::cout<<"Item : "<<arr[search]<<"\n";
    while(k>0)
    {
        if(search==0)
        {
            solution.push_back(arr[++poles]);
            --k;
        }else if(search==arr.size()-1)
        {
            solution.push_back(arr[++poles]); 
            --k;
        }else
        {
            if(arr[left]==arr[search] and arr[right]==arr[left]) 
            {
                solution.push_back(arr[right++]);
                --left;
            }
            else
            {
                if(std::abs(arr[left]-arr[search]) <= std::abs(arr[right]-arr[search]) and (left>-1))
                {
                    solution.insert(solution.begin(),arr[left--]);
                }
                else if ((std::abs(arr[left]-arr[search]) > std::abs(arr[right]-arr[search]) or left==-1) and (right<arr.size()))
                {
                    solution.push_back(arr[right++]);
                }
            }

            --k;
        }
    }
    return solution;
}

//!! better solution than mine
std::vector<int> findClosestElements2(std::vector<int>& arr, int k, int x) 
{
    int left=0,right=arr.size()-k,mid;
    while(left<right){
        mid=(left+right)/2;
        if(x-arr[mid] > arr[mid+k]-x)
            left=mid+1;
        else
            right=mid;
    }
    return std::vector<int> (arr.begin()+left,arr.begin()+left+k);
}  

std::ostream& operator<<(std::ostream &stream,std::vector<int>nums)
{
    for(size_t i=0;i<nums.size();i++) stream<<nums[i]<<" , ";
    return stream;
}

int main()
{
    // std::vector<int> a={1,2,3,4,5,6,7,8};
    // std::cout<<findClosestElements(a,4,8)<<"\n";
    std::vector<int> b={0,1,1,1,2,3,6,7,8,9};
    // std::cout<<findClosestElements(b,9,4)<<"\n";
// std::cout<<findClosestElements2(b,9,4)<<"\n";
}