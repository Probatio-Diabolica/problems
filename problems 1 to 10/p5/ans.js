function swap(arr, ina , inb){
    const temp=arr[ina];
    arr[ina]=arr[inb];
    arr[inb]=temp;
}

function shift(arr){
    let head=0;
    for (let index = 0; index < arr.length; index++) { 
        if(arr[index]<0){
            swap(arr,head,index);
            head++;
        }
    }
}
let arr=[-12 ,11 ,-13 ,-5 ,6 ,-7 ,5 ,-3 ,-6];
console.log(arr);
shift(arr);
console.log(arr);
