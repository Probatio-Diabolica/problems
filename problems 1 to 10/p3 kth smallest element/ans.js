/*
!!Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. 
-> It is given that all array elements are distinct.

Note:-  'l' and 'r' denotes the starting and ending index of the array.

// Example 1:

// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given 
// array is 7.
// Example 2:

// Input:
// N = 5
// arr[] = 7 10 4 20 15
// K = 4
// Output : 15

        Explanation :
        4th smallest element in the given 
        array is 15.

Task: You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.


->  Expected Time Complexity: O(n)
->  Expected Auxiliary Space: O(log(n))

Constraints:
        1 <= N <= 105
        1 <= arr[i] <= 105
        1 <= K <= N
*/
function Qsort(arr,head,tail){
    if(head<tail){
        let index=partition(arr,head,tail);
        Qsort(arr,head,index-1);
        Qsort(arr,index+1,tail);
    }
}
function partition(arr,head,tail){
    const pivot=arr[head];
    let index=head;
    for (let i = head+1; i <= tail; i++){
        if(pivot>=arr[i]){
            index++;
            swap(arr,index,i);
        }
    }
    swap(arr,head,index);
    return index;
}
function swap(arr,a,b){
    let temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

function kthElement(arr,k){
    return arr[k-1];
}
const test=[191, 875, 252, 364, 548, 34, 646, 400, 418, 349];
// console.log(Qsort(test,0,test.length-1));
let a=2;
let b=4;
swap(test,a,b);
console.log(test);
Qsort(test,0,test.length);
console.log(test)
