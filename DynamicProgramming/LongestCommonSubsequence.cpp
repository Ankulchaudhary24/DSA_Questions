/*
Given two strings text1 and text2,
return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 */

//Appraoch 1: Dp with Memoization
int solve(string s1, int ind1, string s2, int ind2, vector<vector<int>>& dp)
    {
        if(ind1 <0 || ind2 <0)
            return 0;
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        
        if(s1[ind1] == s2[ind2])
            return 1+solve(s1, ind1-1, s2, ind2-1, dp);
        
        return dp[ind1][ind2]=max(solve(s1, ind1-1, s2, ind2, dp),solve(s1, ind1, s2, ind2-1, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1 = text1.length();
        int n2 = text2.length();
        
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        
        return solve(text1, n1-1, text2, n2-1, dp);
    }

//Appraoch 2: Dp with Tabulation
int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i] = 0;
        }

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }

        return dp[n][m];
    }

//Space optmied solution
int lcs(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<int> prev(m+1,0), cur(m+1,0);
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev= cur;
    }
    
    return prev[m];
}
