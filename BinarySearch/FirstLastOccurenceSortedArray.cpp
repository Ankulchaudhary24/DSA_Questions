/*

Given a sorted array having N elements, find the indices of the first
and last occurrences of an element X in the given array.

Note: If the number X is not found in the array, return '-1' as an array.

N = 4 , X = 3
arr[] = { 1, 3, 3, 4 }
Output:
1 2
Explanation:
For the above array, first occurence
of X = 3 is at index = 1 and last
occurence is at index = 2.

*/

//Using the BinarySearch Concepts to find the first and last occurence of the element

int firstPosition(vector<int> &arr,int x){
      int s =0;
      int e = arr.size()-1;
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
  
  int lastPosition(vector<int> &arr,int x){
      int s =0;
      int e = arr.size()-1;
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
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int> result;
        result.push_back(firstPosition(arr,x));
        result.push_back(lastPosition(arr,x));
        if(result[0] == -1)
        result.pop_back();
        return result;
    }
