function swap( arr,a, b){
    let tenp=arr[a];
    arr[a]=arr[b]; arr[b]=tenp;

}
let arr=[1,2,3,4];
let a=2;
let b=0;
swap(arr,a,b);
console.log(arr);