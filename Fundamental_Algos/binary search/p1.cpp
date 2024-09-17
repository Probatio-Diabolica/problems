#include<iostream>
#include<vector>
using namespace std;
int FirstOcc(vector<int>& arr, int size, int key){
    int index=-1;
    int tail=size-1;
    int head=0;
    int mid=(head+tail)/2;   
    while(head<=tail){
        if(arr[mid]>key){
            tail=mid-1;
        }
        else if(arr[mid]<key){
            head=mid+1;
        }
        else{ //if arr[mid] ==key
            index=mid;
            tail=mid-1;
        }
        mid=(head+tail)/2;
    }
    return index;
}

int lastOcc(vector<int>& arr, int size, int k){
    int index=-1;
    int head=0,tail=size-1;
    int mid=(head+tail)/2;
    while(head<=tail){
        if(arr[mid]>k){
            tail=mid-1;
        }else if (arr[mid]<k)
        {
            head=mid+1;
        }
        else{
            index=mid;
            head=mid+1;
        }
        mid=(head+tail)/2;
    }
    return index;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first=FirstOcc(vector<int>& arr, int n, int k);
    p.second=lastOcc(vector<int>& arr, int n, int k);
    return p;

}

int main(){
    vector<int> arr={0 ,0 ,1 ,1 ,2, 2 ,2 ,2};
    pair<int,int> ans=firstAndLastPosition(arr,8,2);
    cout<<ans.first<<endl;
    cout<<ans.second;
    // cout<<FirstOcc(arr,8,2)<<endl;
    // cout<<lastOcc(arr,8,2);
    return 0;
}
//https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?interviewProblemRedirection=true