/*


Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.

*/

//Same Approach as the finding the first and last occurence of the element in sorted array

int firstPosition(int arr[],int n,int x){
      int s =0;
      int e = n-1;
      int m = s+(e-s)/2;
      int ans = -1;
      while(s<=e){
          if(arr[m]==x){
           ans = m;
           e = m-1;
          }
          else if(arr[m]<x)
          s = m+1;
          else
          e = m-1;
          m = s+(e-s)/2;
      }
      return ans;
  }
  
  int lastPosition(int arr[],int n,int x){
      int s =0;
      int e = n-1;
      int m = s+(e-s)/2;
      int ans = -1;
      while(s<=e){
          if(arr[m]==x){
           ans = m;
           s = m+1;
          }
          else if(arr[m]<x)
          s = m+1;
          else
          e = m-1;
          m = s+(e-s)/2;
      }
      return ans;
  }


	int count(int arr[], int n, int x) {
	    int first = firstPosition(arr,n,x);
	    if(first == -1)  // if the element is not present in the array then simply return 0;
	      return 0;
	    int last = lastPosition(arr,n,x);
	    int count = last-first+1;
	    return count;
	}
