
/*
-> Given an array (or string), the task is to reverse the array/string.
// Examples : 


// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

// Input :  arr[] = {4, 5, 1, 2}
// Output : arr[] = {2, 1, 5, 4}
*/ 

function reverse(arr){
    const newAdday=[];
    while (arr.length!=0) {
        newAdday.push(arr.pop());
    }   
    return newAdday;
}
console.log(reverse([1,2,3,4]));