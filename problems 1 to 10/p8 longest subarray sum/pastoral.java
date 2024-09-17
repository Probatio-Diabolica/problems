/**
 * pastoral
 */
public class pastoral {
    static int bigga(int a,int b){
        if(a>b){
            return a;
        }
        return b;
    }

    static int maxsubarr(int arr[]){
        int sum=0;
        int max=arr[0];
        for (int i = 0; i < arr.length; i++) {
            sum=sum+arr[i];
            max=bigga(max,sum);
            sum=bigga(sum,0);
        }
        return max;
    }
    
    public static void main(String Args[]){
        int arr[]={5,4,-1,7,8};
        System.out.println(maxsubarr(arr));
    }
    
}