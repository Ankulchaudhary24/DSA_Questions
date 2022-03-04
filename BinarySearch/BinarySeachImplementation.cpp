/*

Given a sorted array of size N and an integer K, find the position at which K is present in the array using binary search.

Input:
N = 5
arr[] = {1 2 3 4 5} 
K = 4
Output: 3
Explanation: 4 appears at index 3.

N = 5
arr[] = {11 22 33 44 55} 
K = 445
Output: -1
Explanation: 445 is not present.

*/

//Iterative Approach

int binarysearch(int arr[], int n, int k){
        int start =0;
        int end = n-1;
        int mid = start+(end-start)/2; // use this instead of (e+s)/2 to avoid overflow 
  
        while(start<=end){
            if(arr[mid]==k)
            return mid;
          
            else if(arr[mid]<k)
            start = mid+1;
          
            else
            end = mid-1;
            mid = start+(end-start)/2;
        }
        return -1;
    }

//Recursive Approach

int binarySearch(int arr[], int l, int r, int x)
     {
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}
