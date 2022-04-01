/*
You have been given an N*M matrix filled with integer numbers, 
find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
From a cell in a row, you can move to another cell directly below that row,
or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.

Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)
*/

//Appraoch 1: Recusive Solution
int solve(int i , int j, vector<vector<int>> &matrix)
{
    if(j<0 || j>=matrix[0].size())
        return -1e9;
    if(i == 0) 
        return matrix[0][j];
     
    int up = matrix[i][j] + solve(i-1, j, matrix);
    int leftDia = matrix[i][j] + solve(i-1, j-1, matrix);
    int rightDia = matrix[i][j] + solve(i-1, j+1, matrix);
    
    return max(up, max(leftDia, rightDia));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int maxi = -1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<m; i++)
    {
       maxi = max(maxi, solve(n-1, i, matrix)); 
    }
    return maxi;
}

//Appraoch 2: Dp with Memoization
int solve(int i , int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if(j<0 || j>=matrix[0].size())
        return -1e9;
    if(i == 0) 
        return matrix[0][j];
     if(dp[i][j] != -1)
         return dp[i][j];
    int up = matrix[i][j] + solve(i-1, j, matrix,dp);
    int leftDia = matrix[i][j] + solve(i-1, j-1, matrix, dp);
    int rightDia = matrix[i][j] + solve(i-1, j+1, matrix, dp);
    
    return dp[i][j] = max(up, max(leftDia, rightDia));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int maxi = -1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for(int i=0; i<m; i++)
    {
       maxi = max(maxi, solve(n-1, i, matrix, dp)); 
    }
    return maxi;
}

//Appraoch 3: Dp with Tabulation

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    
    int maxi = -1e9;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
}

//Space optimized Dp with Tabulation

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int> prev(m,0), cur(m,0);
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        prev[j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + prev[j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += prev[j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += prev[j+1];
            else rightDiagonal += -1e9;
            
            cur[j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
        
        prev = cur;
    }
    
    int maxi = -1e9;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,prev[j]);
    }
    
    return maxi;

}
