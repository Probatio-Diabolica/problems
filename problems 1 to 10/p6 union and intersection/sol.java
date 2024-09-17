class sol{

    static void swap(int arr[], int a, int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    static int partition(int arr[], int head, int tail){
        int index=head;
        int pivot=arr[head];
        for(int i=head+1;i<=tail;i++){
            if(pivot>=arr[i]){
                index++;
                swap(arr, index, i);
            }
        }
        swap(arr,index,head);
        return index;
    }
    static void Qsort(int arr[],int head,int tail){
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
    static int onion(int arr[],int add[]){
        int adday[]=new int[arr.length+add.length];

        for(int i=0;i<arr.length;i++) adday[i]=arr[i];
        for(int i=0;i<add.length;i++) adday[i+arr.length]=add[i];
    
        Qsort(adday,0,adday.length-1);     
        int count=1;
        for(int i=1;i<adday.length;i++){
            if(adday[i]!=adday[i-1]) {
                count++;
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int arr[]={1,3,100,4,5,6};
        int add[]={0,8,2,2,1,2};
        int ans=onion(arr, add);
        System.out.print( ans);
    }
}