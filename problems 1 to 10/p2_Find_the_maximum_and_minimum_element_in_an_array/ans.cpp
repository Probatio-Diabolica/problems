#include<bits/stdc++.h>
using namespace std;
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

// C++ implementation of the above approach


struct Pair {
	int min;
	int max;
};

Pair getMinMax(int arr[], int n) 
{
	Pair minmax;
    minmax.min=arr[0];
    minmax.max=arr[0];
    for(int i=1;i<n;i++){
        if(minmax.min>arr[i]){
            minmax.min=arr[i];
        }
        else if (minmax.max<arr[i])
        {
            minmax.max=arr[i];
        }         
    }
	return minmax;
}

int main()
{
	int arr[] = { 646 , 321 , 435 , 267 , 508 , 283 , 424 , 175 , 82 , 570 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	Pair minmax = getMinMax(arr, arr_size);

	cout << "Minimum element is " << minmax.min << endl;
	cout << "Maximum element is " << minmax.max << endl;

	return 0;
}

// This code is contributed by Tapesh(tapeshdua420)
