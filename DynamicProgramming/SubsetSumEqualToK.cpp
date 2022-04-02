/*
Given an array of non-negative integers, and a value sum, 
determine if there is a subset of the given set with sum equal to given sum. 

Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

*/

//Approach 1: Recursive solution
bool solve(int ind, int target, vector<int> arr)
    {
        if(ind == 0)
            return arr[0] == target;
        
        if(target == 0)
            return true;
            
        bool notTake = solve(ind-1, target, arr);
        bool take = false;
        if(arr[ind] <= target)
            take = solve(ind-1, target- arr[ind], arr);
            
        return take | notTake;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return solve(n-1, sum, arr); 
    }

//Appraoch 2: Dp with Memoization
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target==0)
            return true;
        
        if(ind == 0)
            return arr[0] == target;
        
        if(dp[ind][target]!=-1)
            return dp[ind][target];
            
        bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
        
        bool taken = false;
        if(arr[ind]<=target)
            taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
            
        return dp[ind][target]= notTaken||taken;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
       vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return subsetSumUtil(n-1,sum,arr,dp); 
    }

//Dp with Tabulation
 bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    int k = sum;
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k]; 
    }

//Dp with Space optimized
bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    int k = sum;
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];
    }
