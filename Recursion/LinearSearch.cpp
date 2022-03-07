/*
Given an array Arr of N elements and a integer K. Your task is to return the position of first occurence of K in the given array.
Note: Position of first element is considered as 1.

Example 1:

Input:
N = 5, K = 16
Arr[] = {9, 7, 2, 16, 4}
Output: 4
Explanation: K = 16 is found in the
given array at position 4.

*/
int firstOccurence(int arr[], int i , int n , int k){
        if(i == n)
	    return -1;
	    
	    if(arr[i]==k)
	    return i+1;
	    
	    return firstOccurence(arr,i+1,n,k);
}

int search(int arr[], int n, int k) {
	    return firstOccurence(arr,0,n,k);
}
