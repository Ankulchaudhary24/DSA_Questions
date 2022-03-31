/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix,
your destination is point ‘B’, which is the bottom-right cell of the same matrix.
Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’,

your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j],
you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

*/
// The best solution for this problem is using the combinatorics
//Approach 1:Recusive Solution
int solve(int i, int j)
{
    if(i == 0 && j == 0)
        return 1;
    if(i < 0 || j < 0)
        return 0;
    
    int up = solve(i-1, j);
    int right = solve(i, j-1);
    return up+right;
}
int uniquePaths(int m, int n) {
	return solve(m-1, n-1);
}

//Appraoch 2: DP with memoization
int solve(int i, int j, vector<vector<int> > &dp)
{
    if(i == 0 && j == 0)
        return 1;
    if(i < 0 || j < 0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = solve(i-1, j, dp);
    int right = solve(i, j-1, dp);
    return dp[i][j]=up+right;
}
int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m, vector<int> (n,-1));
	return solve(m-1, n-1, dp);
}

//Appraoch 3: Dp with Tabulation

int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m, vector<int> (n,0));
    dp[0][0] = 1;
    for(int i =0; i<m; i++)
    {
        dp[i][0] = 1;
    }
    
    for(int i =0; i<n; i++)
    {
        dp[0][i] = 1;
    }
    for(int i =1; i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
	return dp[m-1][n-1];
}

//Appraoch 4: Space optimized dp

int uniquePaths(int m, int n) {
    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];
}
