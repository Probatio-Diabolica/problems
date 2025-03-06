#include"includes.hpp"


// void swap(int * a, int * b )
// {
//     int temp = *a;
//     * a = * b;
//     *b = temp;
// }

// int partition(vector<int>& arr, int low, int high) {
  
//     int pivot = arr[high];
  
//     int i = low - 1;
//     for (int j = low; j <= high - 1; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
    
//     // Move pivot after smaller elements and
//     // return its position
//     swap(arr[i + 1], arr[high]);  
//     return i + 1;
// }




// void Qsort(int head, int tail,iArray& nums)
// {
//     if(head<=tail)
//     {
//         int part = partition(head, tail,nums);
//         Qsort(head,part-1,nums);
//         Qsort(part+1,tail,nums);
//     }
// }

// int maxOperations(vector<int>& nums, int k) {
//     int sol=0;
//     Qsort(0,nums.size()-1,nums);
//     int l=0, r=nums.size()-1;
//     while(l<r)
//     {
//         if(k > nums[r]+nums[l])
//         {
//             ++l;
//         }
//         else if(k<nums[r]+nums[l])
//         {
//             --r;
//         }
//         else
//         {
//             ++sol;
//             ++l, --r;
//         }
//     }
//     return sol;
// }


int maxOperations(vector<int>& nums, int k) 
{
    iMap map;
    int sol=0;
    for(int i=0;i<nums.size();i++)
    {
        if(map[k-nums[i]]==0) map[nums[i]]++;
        else
        {
            --map[k-nums[i]];
            ++sol;
        }
    }
    return sol;
}

int main()
{
    iArray x={1,2,3,4};
    std::cout<<maxOperations(x,5);
}