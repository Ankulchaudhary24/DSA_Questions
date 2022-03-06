/*

Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

*/

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
        queue<long long> q; // Making Queue to store the first Negative element of the current window
        vector<long long> ans;
        
  //Step 1: Processing the first K elements
        for(long long int i=0;i<k;i++){
            if(arr[i]<0)
              q.push(i);
        }
        
   //Storing ans for first window
        if(!q.empty())
            ans.push_back(arr[q.front()]);
        else
            ans.push_back(0);
        
        //Traversing the array after first window.
        for(long long int i =k;i<n;i++){
           
          //removal logic
            if(!q.empty() && i-q.front()>=k)
               q.pop();
            
          //Addition Logic
            if(arr[i]<0)
            q.push(i);
            
          //Storing ans
            if(!q.empty())
            ans.push_back(arr[q.front()]);
            else
            ans.push_back(0);
        }
        return ans;
 }
