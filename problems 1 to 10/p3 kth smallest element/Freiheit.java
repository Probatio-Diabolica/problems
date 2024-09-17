/*
!!Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. 
-> It is given that all array elements are distinct.

Note:-  'l' and 'r' denotes the starting and ending index of the array.

// Example 1:

// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given 
// array is 7.
// Example 2:

// Input:
// N = 5
// arr[] = 7 10 4 20 15
// K = 4
// Output : 15

        Explanation :
        4th smallest element in the given 
        array is 15.

Task: You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.


->  Expected Time Complexity: O(n)
->  Expected Auxiliary Space: O(log(n))

Constraints:
        1 <= N <= 105
        1 <= arr[i] <= 105
        1 <= K <= N
 */
// import java.util.Random;
class A{
        public void show(){
                System.out.println("Fus roh dah");
        }
}
public class Freiheit {
        
        static int partition(int arr[],int head,int tail){
                int pivot=arr[head];
                int index=head;
                for(int i=head+1;i<=tail;i++){
                        if(pivot>=arr[i]){
                                index++;
                                swap(arr,index,i);
                        }
                }
                swap(arr,index,head);
                return index;
        }
        static void swap(int arr[],int index,int index2){
                int temp=arr[index];
                arr[index]=arr[index2];
                arr[index2]=temp;
        }
        static void Qsort(int arr[], int head ,int tail){
                if(head<tail+1){
                        int index=partition(arr, head, tail);
                        Qsort(arr,head,index-1);
                        Qsort(arr,index+1,tail);
                }
        }
        static void printarr(int arr[]){
                int size=arr.length;
                for(int i=0;i<size;i++){
                        if(i==0) System.out.print("[");
                        System.out.print(arr[i]);
                        if(i!=size-1) System.out.print(" , ");
                        if(i==size-1) System.out.print("]\n");
                    }
                
        }
        static int kthElement(int arr[],int k){
                return arr[k-1];
        }
        public static void main(String[] Args){
                // A a= new A();
                // a.show();
                
                //-> code below does not works 
                // int a=10;
                // int b=78;
                // swap(a,b);
                // System.out.println("a was 10, now a is "+a+" wile b was 78 now it is "+b);
                //Random randInt = new Random();
                int arr[]={1 , 3 , 2 , 4 , 5 , 6 , 0 , 8 , 9 , 2 , 1 , 2};
                //int size=11;
                // for(int i=0;i<size;i++){
                //     arr[i]=randInt.nextInt(1000);
                // }
                printarr(arr);

                Qsort(arr, 0, arr.length-1);
                printarr(arr);
        }
}