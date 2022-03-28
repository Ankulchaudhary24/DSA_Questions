/*
Given an array Arr of size N containing positive integers.
Find the maximum sum of a subsequence such that no two
numbers in the sequence should be adjacent in the array.

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.
Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous  subsequence with maximum
sum.
*/

//Appraoch 1: Recusive Solution
int solve(int *arr, int n)
    {
       if(n ==0)
	   return arr[0];
	   
	   if(n <0)
	   return 0;
	   
	   int pick = arr[n]+solve(arr, n-2);
	   int notPick = solve(arr, n-1);
	   
	   return max(pick, notPick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   return solve(arr, n-1);
	}


//Appraoch 2: Dp with the Memoization technique
int solve(int *arr, int n, vector<int> &dp)
    {
       if(n ==0)
	   return arr[0];
	   
	   if(n <0)
	   return 0;
	   
	   if(dp[n]!= -1)
	   return dp[n];
	   int pick = arr[n]+solve(arr, n-2, dp);
	   int notPick = solve(arr, n-1, dp);
	   
	   return dp[n] = max(pick, notPick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n, -1);
	   return solve(arr, n-1, dp);
	}

//Dp with tabulation
int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    
    dp[0]= arr[0];
    
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}

//Space optimized approach
int solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
