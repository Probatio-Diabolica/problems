"""

-> Given an array (or string), the task is to reverse the array/string.
// Examples : 


// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

// Input :  arr[] = {4, 5, 1, 2}
// Output : arr[] = {2, 1, 5, 4}
"""
import numpy as np
def reverse(arr):
    array=np.array([])
    
    while (len(arr)!=0):
        array=np.append(array,arr.pop())

    return array

if __name__=="__main__": # the int main of python
    print(reverse([1,2,3,4]))