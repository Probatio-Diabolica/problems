#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void swap(int& in1, int& in2){
        int temp=in1;
        in1=in2;
        in2=temp;
    }
    void sortColors(vector<int>& arr) {
        int low=0,now=0,end=arr.size()-1;
	while(now<=end)
	{
		switch(arr[now])
		{
			case 0:
                swap(arr[now],arr[low]);
                now++;
                low++;
                break;
            case 1:
                now++;
                break;
            default:
                swap(arr[now],arr[end]);
                end--;
                break;
		}
	}
    }
    void printarr(vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<", ";
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,2,0,1};
    sol.printarr(nums);
    cout<<endl;
    sol.sortColors(nums);
    sol.printarr(nums);
    return 0;
}