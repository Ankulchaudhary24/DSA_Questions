/*

An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
Given an array arr[] of size N, find the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 


Example 1:

Input:
N = 3
arr[] = {1,2,3}
Output: 2
Explanation: index 2 is 3.
It is the peak element as it is 
greater than its neighbour 2.

There will be Three cases:
CASE 1 : Ascending Ordered Array
CASE 2 : Descending Ordered Array
CASE 3 : Mountain Array

*/

int peakElement(int arr[], int n)
    {
       int s=0;
       int e = n-1;
       int m = s+(e-s)/2;
       while(s<e){
           if(arr[m]<arr[m+1])
           s = m+1;
           else
           e = m;
           m = s+(e-s)/2;
       }
       return e;
    }
