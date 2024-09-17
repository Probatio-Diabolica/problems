
/*
->The Dutch National Flag algorithm, also known as three-way partitioning, was designed by Edsger Dijkstra to sort an array of objects with three distinct keys. 

-> The algorithm separates the array into three groups based on the values of these keys. It is particularly useful when sorting arrays with multiple duplicate values.

// The algorithm operates on an array of elements, and its goal is to rearrange the elements such that the elements with the first key appear first, followed by elements with the second key, and finally, elements with the third key.

task 1: Initialize three pointers:
    ->  "low" points to the beginning of the array.
    ->  "mid" points to the current element being processed.
    ->  "high" points to the end of the array.

task 2: Traverse the array:
    $   While mid is less than or equal to high, repeat the following steps.:

        task a) Case 1 (Element at mid is the first key):
            $   If the element at mid is the first key, swap the elements at low and mid, and increment both low and mid.

        task b) Case 2 (Element at mid is the second key):
            $   If the element at mid is the second key, leave it in its place and just increment mid.
        
        task c) Case 3 (Element at mid is the third key):
            $   If the element at mid is the third key, swap the elements at mid and high, and decrement high.

note: The algorithm continues until mid crosses high, ensuring that the array is partitioned into three sections.

*/ 

public class dnf {
    static void swap(int[] arr, int i, int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    static void sort(int[] arr){
        int high=arr.length-1;
        int low=0;
        int mid=0;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr,mid,low);
                mid++; low++;
            }else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr,mid,high);
                high--;
            }
        }
    }
    static void printarr(int arr[]){
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+",");
        }
    }
    public static void main(String[] args){
        int arr[]={0,0,1,2,2,0,1};
        printarr(arr);
        sort(arr);
        System.out.println("\n");
        printarr(arr);

    }
}
