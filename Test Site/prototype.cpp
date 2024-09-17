#include<iostream>
#include<vector>
using namespace std;
// ---------------------------------------------------------------------------------------------------------------------------------------------



// ---------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------

/*
int pivot(vector<int> &nums,int target){
        int ans=-1;
        int head=0,tail=nums.size()-1,mid=(nums.size()-1)/2,piviot;
        while(head<=tail){
            if(nums[mid]<nums[0]){
                !! imp
                piviot=mid;
                tail=mid-1;
            }else if(nums[mid]==nums[0]){
                piviot=0;
                tail=mid+1;
            }else{
                piviot=0;
                head=mid+1;                        
            }mid=head+(tail-head)/2;
        }
        cout<<"piviot : "<<piviot<<endl;
//  -> Deviding the search space
        if(nums[0]<target){
            head=0;
            tail=piviot;
        }else if (nums[0]==target ){
            ans =0;
        }else{
            head=piviot;
            tail=nums.size()-1;
        }

        cout<<"head : "<<head <<" Tail : "<<tail<<endl;;
//  ->   Binary search time
        mid=head+(tail-head)/2;
        while(head<=tail){
            if(nums[mid]>target){
                tail=mid-1;
            }else if(nums[mid]<target){
                head=mid+1;
            }else{
                ans=mid; //?? Something is wrong here 
                head=mid+1;
                tail=mid-1; 
            }
            mid=head+(tail-head)/2;
        }
        return ans;
}
int main(){
    //vector<int> nums={1,2,3,4};
    vector<int> nums={1,1,2,0};
    cout<<"target is at : "<<pivot(nums,2);
    return 0;
}
*/

// ---------------------------------------------------------------------------------------------------------------------------------------------
    // int findMin(vector<int> &nums){
    //     int head=0,tail=nums.size()-1,mid=tail/2,smol=0;
    //     while(head<=tail){
    //         if (nums[mid]>nums[0])
    //         {                
    //             head=mid+1;
    //         }
    //         else if (nums[mid]<nums[0])
    //         {
    //             smol=mid;
    //             tail=mid-1;
    //         }
    //         else
    //         {
    //             smol=0;
    //             head=mid+1;
    //         }
    //         mid=head+(tail-head)/2;
    //     }
    //     return nums[smol];
    // }
    int findMin(vector<int> &nums){
            int head=0,tail=nums.size()-1;
            int mid=tail/2;
            while(head<tail){
                if(nums[0]>nums[mid]){
                    // Normal situation
                    tail=mid;
                }else{
                    head=mid+1;
                }
                mid=head+ ((tail-head)/2);
            }
            return nums[head];
        }


int main(){
    // 1,2,3,4,0 success
    // 6,7,8,9,1,2,3,4,5 not successfull
    // 3,4,1,2 is successful
    // 5,6,7,8,9,1,2,3,4 successfull
    // 6,7,8,9,1,2,3,4,5 wtf successfull
    // 5,5,5,6,1,2,3,4 works
    // 4,5,6,7,0,1,2 successful
    //  2,1 successfull
    //  1,2,3,4
    vector<int> nums={1,2,3,4};
    //vector<int> numb={{1,2,3,4,0},{6,7,8,9,1,2,3,4,5},{3,4,1,2},{5,6,7,8,9,1,2,3,4},{2,1},{1}};
    // for(int i=0;i<5;i++){
        
    // }
    cout<<"Smallest : "<<findMin(nums);
    
    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------
