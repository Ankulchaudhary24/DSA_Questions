/*

Given an integer array arr of size N, the task is to divide it into two sets S1 and S2
such that the absolute difference between their sums is minimum and find the minimum difference
Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

*/

//Appraoch 
//Step 1: Findingthe total sum of the array
//Step 2: Using the space optmized concept of subset sum and the last row will conatin
// info whether the sum from 0 to tatal sum is possible or not
//Step 3: finding out the minimum sum 

int minDifference(int arr[], int n)  { 
        int sum =0;
        for(int i= 0; i<n; i++)
        {
            sum +=arr[i];
        }
        vector<bool> prev(sum+1,false);
        
        prev[0] = true;
        
        if(arr[0]<=sum)
            prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            vector<bool> cur(sum+1,false);
            cur[0] = true;
            for(int target= 1; target<=sum; target++){
                bool notTaken = prev[target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];
            
                cur[target]= notTaken||taken;
            }
            prev = cur;
        }
        
        int mini = 1e9;
        for(int i=0; i<=sum/2;i++)
        {
            if(prev[i] == true)
            {
                mini = min(mini, (sum-(2*i)));
            }
        }
        return mini;
	} 
