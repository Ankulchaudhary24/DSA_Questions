/*
There is a frog on the 1st step of an N stairs long staircase. 
The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.
If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. 
Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
*/

//Approch 1: Recursive solution
int solve(int n, vector<int> &heights)
{
    if(n == 0)
        return 0;
    int left = solve(n-1, heights)+abs(heights[n]-heights[n-1]);
    int right =INT_MAX;
    if(n >1)
        right = solve(n-2,heights)+abs(heights[n]-heights[n-2]);
    
    return min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
 return solve(n-1, heights);   
}

//Appraoch 2: Dp solution with memoization
#include <bits/stdc++.h>

int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    int left = solve(n-1, heights, dp)+abs(heights[n]-heights[n-1]);
    int right =INT_MAX;
    if(n >1)
        right = solve(n-2,heights, dp)+abs(heights[n]-heights[n-2]);
    
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
 return solve(n-1, heights, dp);   
}

// Dp Appraoch with tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    for(int i =1; i<n;i++)
    {
        int fs = dp[i-1] +abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1)
            ss =dp[i-2] +abs(heights[i]-heights[i-2]);
        
        dp[i] = min(fs, ss);
    }
    return dp[n-1];
}

//Approach 4: optimising the dp array to constant space
int frogJump(int n, vector<int> &heights)
{
    int prev2 =0, prev =0;
    for(int i =1; i<n;i++)
    {
        int fs = prev +abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1)
            ss =prev2 +abs(heights[i]-heights[i-2]);
        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
