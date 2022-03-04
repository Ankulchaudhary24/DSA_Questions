/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key.
The task is to find the index of the given element key in the array A.

Example 1:

Input:
N = 9
A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
key = 10
Output:
5
Explanation: 10 is found at index 5.

Example 2:

Input:
N = 4
A[] = {3, 5, 1, 2}
key = 6
Output:
-1
Explanation: There is no element that has value 6

*/


int pivotIndex(int arr[], int n){
        int s = 0;
        int e = n-1;
        int m = s+(e-s)/2;
        while(s<e){
            if(arr[m]>=arr[0])
            s = m+1;
            else
            e = m;
            m = s+(e-s)/2;
        }
        return e;
    } 

int binarySearch(int arr[], int s,int e, int key){
        int m = s+(e-s)/2;
        while(s<=e){
            if(arr[m]==key)
            return m;
            else if(arr[m]<key)
            s = m+1;
            else
            e = m-1;
            m = s+(e-s)/2;
        }
        return -1;
}

int search(int* arr, int n, int key) {
    int p = pivotIndex(arr,n);
    int left = binarySearch(arr,0,p-1,key);
    int right = binarySearch(arr,p,n-1,key);
    if(left ==-1)
        return right;
    else
        return left;
}
