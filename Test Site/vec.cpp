#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // void swap(int *a, int *b){
    //     int temp=*a;
    //     *a=*b;
    //     *b=temp;
    // }
    // void reverse(vector<int> &nums,int head,int tail){
    //     while(head<tail){
    //         swap(&nums[head],&nums[tail]);
    //         head++;
    //         tail--;
    //     }
    // }
    // void rotate(vector<int>& nums, int k) {
    //     k=k%nums.size();
    //     reverse(nums,0,nums.size());
    //     reverse(nums,0,k);
    //     reverse(nums,k,nums.size());
    // }
    void printarr(vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<", ";
        }
    }
};
int main(int argc, char* argv[]){
    // Solution sol;
    vector<int> abc={1,2,3,4,5};
    // sol.rotate(abc,3);
    // sol.printarr(abc);
    cout<<abc[0];
    return 0;
}