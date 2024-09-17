/*
!! Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

// Examples:

// Input: arr[] = {3, 5, 4, 1, 9}
// Output: Minimum element is: 1
//               Maximum element is: 9

// Input: arr[] = {22, 14, 8, 17, 35, 3}
// Output: Minimum element is: 3
//         Maximum element is: 35

*/
import java.util.Random;
//import java.util.Scanner;

public class ans {
    static void printarr(int[] arr,int size){
        for(int i=0;i<size;i++){
            if(i==0) System.out.print("[");
            System.out.print(arr[i]);
            if(i!=size-1) System.out.print(" , ");
            if(i==size-1) System.out.print("]\n");
        }
        
    }
    static int[] minMax(int arr[],int size){
        int min=arr[0];
        int max=arr[0];
        int output[]={2,1};//random sizes *does not matters*

        for(int i=1;i<size;i++){
            if(max<arr[i]){
                max=arr[i];
            }
            else if (min>arr[i]) {
                min=arr[i];
            }
        }
        output[0]=min;
        output[1]=max;
        return output;
    }
    public static void main(String[] args) {
        Random randInt = new Random();
        int arr[]={1,2,3,4,5,6,12,43,54,6};
        int size=10;
        for(int i=0;i<size;i++){
            arr[i]=randInt.nextInt(1000);
        }
        printarr(arr, size);
        int max=minMax(arr,size)[1];
        int min=minMax(arr,size)[0];
        System.out.println("max = "+max+" min= "+min);
        
        // Scanner scanf = new Scanner(System.in);
        // String abc= scanf.nextLine();

    }
}
