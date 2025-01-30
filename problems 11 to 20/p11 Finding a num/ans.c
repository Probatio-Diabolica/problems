#include<stdio.h>
int piviot(int *arr, int head, int tail){
    int mid=head+(tail-head)/2;
    if(head<tail){
        if(arr[0]>arr[mid]){
            return piviot(arr,head,mid);
        }
        else if(arr[mid]>arr[0]){
            return piviot(arr,mid+1,tail);
        }else{
            return mid+1;
        }
    }else{
        return mid;
    }
    return mid;
}

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

int search(int *nums, int numsSize,int target){
    
    if(nums[0]>target){

        return bs(nums,piviot(nums,0,numsSize-1),numsSize-1,target);
    
    }else if(nums[0]<target){

        return bs(nums,0,piviot(nums,0,numsSize-1),target); 
    
    }else{
        return 0;
    }
}

int main(int argc, char **argv){
    int nums[] ={1,2,3,4,5,6};
    //printf("%d",piviot(nums,0,5));

    // printf("\n%d \n-\n",search(nums,5,6));

    // int numsb[]={10,12,14,19,1,3,5,6};
    // printf("\n%d\n-\n",search(numsb,8,6));
     int numsc[]={1,3};
    //printf("\n%d",piviot(numsc,0,1));
    printf("\n%d",search(numsc,2,3));
    return 0;
}