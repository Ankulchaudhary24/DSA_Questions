/*

Given an array arr[] of size N, check if it is sorted in non-decreasing order or not. 

Example 1:

Input:
N = 5
arr[] = {10, 20, 30, 40, 50}
Output: 1
Explanation: The given array is sorted.

Example 2:

Input:
N = 6
arr[] = {90, 80, 100, 70, 40, 30}
Output: 0

*/

bool arraySortedOrNot(int arr[], int n) {
    if(n==0 || n==1)
    return true;
    
    if(arr[n-1]>=arr[n-2])
    return arraySortedOrNot(arr,n-1);
    
    else
    return false;
    
}
