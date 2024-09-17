#include<stdio.h>

int bs(int *arr,int head,int tail,int target){
    int mid = head+(tail-head)/2;
    if(head<=tail){

        if(arr[mid]>target){

            return bs(arr,head,mid-1,target);
            
        }
        else if (arr[mid]<target)
        {
            return bs(arr,mid+1,tail,target);

        }else{

            return mid;

        }
    }else{

        return -1;

    }
}

int main(int argc,char **argv){
    int arr[]={1,5,7,9,11,56,78};
    
    bs(arr,0,6,9);
    return 0;
}