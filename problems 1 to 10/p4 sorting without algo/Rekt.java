class Solution {
    public void swap(int arr[],int index, int index2){
        int temp=arr[index];
        arr[index]=arr[index2];
        arr[index2]=temp;
    }
    public void sortColors(int[] nums) {
        int right=nums.length-1;
        int left=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==2){
                swap(nums,i,right);
                right--;
                
            }else if(nums[i]==0){
                swap(nums,i,left);
                left++;
            }else{
                if(nums[i]<nums[left]){
                    swap(nums,i,left);
                    right--; left++;
                }else if(nums[i]>nums[left]){

                }
            }
        }
    }

    public void printarr(int arr[]){
        for (int i : arr) {
            System.out.println(i);
        }
    }
    
}
public class Rekt {
    static void swap(int arr[],int index, int index2){
        int temp=arr[index];
        arr[index]=arr[index2];
        arr[index2]=temp;
    }

    //approach A: intuitative
    // static void sortColors(int[] nums) {
    //     int zero=0;
    //     int one=0;
    //     int two=0;
    //     for(int i: nums){
    //         switch (i) {
    //             case 0:
    //                 zero++;
    //                 break;

    //             case 1:
    //                 one++;
    //                 break;

    //             case 2:
    //                 two++;
    //                 break;

    //             default:
    //                 break;
    //         }
    //     }
    //     one=one+zero;
    //     two=two+one;
    //     for(int i=0;i<nums.length;i++){
    //         if(i<zero) {
    //             nums[i]=0;
    //         }else if(i<one){
    //             nums[i]=1;
    //         }else if(i<two){
    //             nums[i]=2;
    //         }
    //     }
    // }

    //DNF
    static void sortColors(int[] nums){
        int one=0,two=nums.length-1,zero=0;
        while(one<=two){
            if(nums[one]==0){
                swap(nums, one, zero);
                one++;
                zero++;
            }else if(nums[one]==1){
                one++;
            }else{
                swap(nums, two, one);
                two--;
            }
        }
    }
    static void printarr(int arr[]){
        for (int i : arr) {
            System.out.print(i+" ");
        }
    }

    public static void main(String[] args){
        //Solution sol=new Solution();
        int arr[]={1,0,1,2,2,0};
        // sol.sortColors(arr);
        // sol.printarr(arr);
        sortColors(arr);
        System.out.println("\n");
        printarr(arr);


    }
}
