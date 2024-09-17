#include <iostream>
using namespace std;
/*
-> Given an array (or string), the task is to reverse the array/string.
// Examples : 


// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

// Input :  arr[] = {4, 5, 1, 2}
// Output : arr[] = {2, 1, 5, 4}
*/
void printarr(int arr[], int size) 
{ 
   for (int i = 0; i < size; i++) 
   cout << arr[i] << " "; 
  
   cout << endl; 
}   
void reverse(int array[],int end, int start=0){
    
    int temp;
    while(start<end){
        temp=array[start];
        array[start]=array[end];
        array[end]=temp;
        start++;
        end--;
    }
    
}


int main()  
{ 
    int arr[] = {1, 2, 3, 4, 5, 6}; 
      
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    // To print original array  
    printarr(arr, n); 
      
    // Function calling 
    reverse(arr, n-1, 0); 
      
    cout << "Reversed array is" << endl; 
      
    // To print the Reversed array 
    printarr(arr, n); 
      
    return 0; 
} 