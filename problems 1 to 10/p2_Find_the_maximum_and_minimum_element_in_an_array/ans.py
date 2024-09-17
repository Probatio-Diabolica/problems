"""
!! Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

// Examples:

// Input: arr[] = {3, 5, 4, 1, 9}
// Output: Minimum element is: 1
//         Maximum element is: 9

// Input: arr[] = {22, 14, 8, 17, 35, 3}
// Output: Minimum element is: 3
//         Maximum element is: 35

"""
import random as rd
import numpy as np

def minMax(item)->list:
    if(len(item)==0):
        return  ["empty array"]
    else:
        max:int=item[0]
        min:int=item[0]
        for i in item:
            if(max<=i):
                max=i
            elif(min>=i):
                min=i
            else:
                "do nothing"   
        return [min , max]

# https://www.youtube.com/watch?v=-098e9w1opQ
if __name__=="__main__":
    arr=np.array(())
    for i in range(0,rd.randint(4,8)):
        arr=np.append(arr,rd.randint(0,10))
    print(arr)
    print(minMax(arr))