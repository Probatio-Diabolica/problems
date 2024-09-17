/*
-> Given an array (or string), the task is to reverse the array/string.
// Examples : 


// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

// Input :  arr[] = {4, 5, 1, 2}
// Output : arr[] = {2, 1, 5, 4}
*/ 

public class ans{
    static void reverse(int arr[],int start,int end){
        int temp=0;
        while(start<end-1){
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;end--;
        }

    }
    static void printarr(int arr[],int size){
        for (int i = 0; i < size; i++)
        {   
            if(i==0) System.out.print("[");
            System.out.print(arr[i]);
            if(i!=size-1) System.out.print(",");
            if(i==size-1) System.out.print("]\n");
        
        }
    }

    public static void main(String[] args){
        int arr[]={1,2,3,4,5};
        
        System.out.println("finally");
        printarr(arr,5);
        reverse(arr, 0, 4);
        printarr(arr,5);
    }
}
