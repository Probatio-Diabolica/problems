
public class Enigkeit {
    static void swap(int arr[], int in1, int in2){
        int temp=arr[in1];
        arr[in1]=arr[in2];
        arr[in2]=temp;
    }
    static void shift(int arr[]){
        int head=0;
        int curr=0;
        // for(int curr=0;curr<arr.length;curr++){
        //     if()
        // }
        while (curr<arr.length) {
            if(arr[curr]<0){
                swap(arr, head, curr);
                head++; 
                curr++;               
            }else{
                curr++;
            }
        }
    }
    public static void main(String[] args) {
        int arr[]={-12 ,11 ,-13 ,-5 ,6 ,-7 ,5 ,-3 ,-6 };
        shift(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" , ");
        }
    }
}