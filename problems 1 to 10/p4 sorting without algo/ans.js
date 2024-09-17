function swap(arr,a, b){
    let temp=arr[a];    arr[a]=arr[b];   arr[b]=temp;
}

var sortColors = function(nums) {
    let head=0;
    let mid=0;
    let tail=nums.length-1;
    while (mid<=tail) {
        if(nums[mid]==0){
            swap(nums,mid,head);
            mid++;
            head++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums,mid,tail);
            tail--;
        }
    }
};

let arr=[0,1,2,1,2,0];
sortColors(arr);
console.log(arr);
