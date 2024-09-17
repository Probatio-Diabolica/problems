#include<iostream>
#include <vector>
using namespace std;


class ans{
public:
    void swap(int* a, int* b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }

    void shift(vector<int> &arr,int size){
        int head=0;
        int curr=0;
        while(curr<=size-1){
            if(arr[curr]<0){
                swap(&arr[curr],&arr[head]);
                
                head++;
            }
            curr++;
        }
        
        
    }
    void printarr(vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<", ";
        }
    }
    
};


int main(){
    vector<int> arr={-12 ,11 ,-13 ,-5 ,6 ,-7 ,5 ,-3 ,-6 };
    ans an;
    an.printarr(arr);
    cout<<endl;
    an.shift(arr,9);
    an.printarr(arr);
    return 0;
}