#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int head=0,tail=nums.size()-1,mid=(tail)/2;
        while(head<tail){


            //-> If mid== target , return true

            if(nums[mid]==target) return true;
            
            //--- SituationA: If mid = end and start==mid , move head forward and move tail backward by 1 steps both as there are duplicates in the list  
            //--- SituationB: If mid >=start then it means that Target may be in the first half while second half will have 0% chances.
            //--- SituationC: If mid<=head then it means target is in second half(maybe),
            
             if((nums[head]==nums[mid])&&(nums[mid]==nums[tail])){
                /*
                !! this is Situation A where head and tail are same and {Equal to mid}
                */ 
                tail--;
                head++;
                continue;

            }
            if(nums[mid]<=nums[tail]){
                // !! This is situation B
                if((nums[mid]<target)&&(nums[tail]>taget)){
                    head=mid+1;
                }else if(){

                }

            }else{
                // !! This is situation C
                tail=mid-1;
            }
            mid= head+(tail-head) / 2;
        }
        return false;
    }
};
// 2 1, 


bool hello(){
    return true;
}

int main(/*int argc,char **argv*/){
    
    vector<int> nums={1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};//2,5,6,0,0,1,2 success
    int target=2;
    Solution sol;
    cout<<"True="<<hello()<<endl;
    cout<<"result "<<sol.search(nums,target);
    
    return 0;
}