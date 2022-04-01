/*
You are given a triangular array/list 'TRIANGLE'.
Your task is to return the minimum path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. For example,
if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.

*/

//Dp with Memoization
int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle,int n, 
vector<vector<int> > &dp) {
  
  if(i==n-1) return triangle[i][j];
    
  int down = triangle[i][j]+minimumPathSumUtil(i+1,j,triangle,n,dp);
  int diagonal = triangle[i][j]+minimumPathSumUtil(i+1,j+1,triangle,n,dp);
  
  return dp[i][j] = min(down, diagonal);
  
}

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,-1));
    return minimumPathSumUtil(0,0,triangle,n,dp);
    
}

//Dp with Tabulation

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
    
}

//Space optmized Dp tabulation

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<int> front(n,0), cur(n,0);
    
    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+front[j];
            int diagonal = triangle[i][j]+front[j+1];
            
            cur[j] = min(down, diagonal);
        }
        front=cur;
    }
    
    return front[0];
    
}
