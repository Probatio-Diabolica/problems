#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:   
    int first(vector<int> &nums,int head,int tail,int target){
        int mid=head+(tail-head)/2;
        if(head<tail){
            if(nums[mid]<target){
                return first(nums,mid+1,tail,target);
            }else if(nums[mid]==target){
               return first(nums,head,mid,target); 
            }
        }
        return mid;
    }
int second(vector<int> &nums,int head,int tail,int target){
        int mid=head+(tail-head)/2;
        if(head<tail){
            if(nums[mid]>target){
                return second(nums,head,mid-1,target);
            }else if(nums[mid]==target){
               if(nums[mid+1]==target && mid+1 <=tail){
                return second(nums,mid+1,tail,target);
               }
               return second(nums,mid,mid,target);
            }
        }
        return tail;
}
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result={-1,-1};
        int head=0,tail=nums.size()-1;
        int mid=tail/2;
        while (head<=tail)
        {
            if(nums[mid]>target){
                tail=mid-1;
            }else if(nums[mid]<target){
                head=mid+1;
            }else{
                result[0]=first(nums,head,mid,target);
                result[1]=second(nums,mid,tail,target);
                head=tail+1;
            }
            mid=head+(tail-head)/2;
        }
        return result;
    }
};
int main(int argc , char **argv){
    vector<int> nums={1,2,3,3,4,4,4,5,6,7};

    vector<int> numsa={1,1,1,1,1,1,1,1,1,1};
    Solution sol;
    for (int i = 0; i < numsa.size(); i++)
    {
        
        cout<<"For "<<numsa[i]<<" No:"<<i<<endl;
        vector<int> a=sol.searchRange(numsa,numsa[i]);
        cout<<"Begining: "<<a[0]<<endl;
        cout<<"ending: "<<a[1]<<endl<<endl;
        
    }
    
    
    //cout<<sol.first(numsa,0,9,6);
    return 0;
}

/*
!! While the code is perfect, however there are performance concerns,

NOTE: Loops are generally more efficient than recursion regarding time and space complexity. 

---> Recursive calls can lead to increased memory usage because each function call is added to the stack, while a loop only requires a single memory allocation.
*/ 