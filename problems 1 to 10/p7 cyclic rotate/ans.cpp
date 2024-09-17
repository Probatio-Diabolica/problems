#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
    }
    void printarr(vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<", ";
        }
    }
};
int main(int argc, char* argv[]){
    Solution sol;
    vector<int> abc={1,2,3,4,5,6,7};
    sol.rotate(abc,3);
    sol.printarr(abc);
    return 0;
}