public class reimu {
    static void swap(int arr[], int a, int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    static void reverse(int arr[],int head,int tail){
        while(head<tail-1){
            
            swap(arr, head,tail-1);
            head++;tail--;
        }
    }
    static void shifu(int adday[],int by){
        by=by%(adday.length);
        reverse(adday,0,adday.length);
        reverse(adday,0,by);
        reverse(adday,by,adday.length);
    }
    public static void main(String[] Args){
        int arr[]={1,2,3,4,5,11,22,33,44,55};
        shifu(arr, 5);
        //System.out.println((arr.length-1)%5);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}

