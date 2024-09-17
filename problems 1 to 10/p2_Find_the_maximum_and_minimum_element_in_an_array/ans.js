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
function minMax(arr){
    if(arr.length==0){
        return "No elements could be found";
    }else{
        let min=arr[0];
        let max=arr[0];
        for(let i=0;i<arr.length;i++){
            (max<=arr[i]) ? max=arr[i] : (min>arr[i]) ? min=arr[i] : "do nothing";
        }
        return [min,max];
    }
}

const arr=[1,2,3,4,6,7];
console.log(minMax([10,20,43,32,321,6]));
