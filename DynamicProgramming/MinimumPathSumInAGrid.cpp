/*
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID',
with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) 
which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.

*/

//Approach 1: Recusive Solution

int solve(int i, int j, vector<vector<int>> &grid)
{
    if(i==0 && j == 0)
        return grid[0][0];
    if(i < 0 || j < 0)
        return 1e9;
    int up = grid[i][j] + solve(i-1, j, grid);
    int left = grid[i][j] + solve(i, j-1, grid);
    return min(up , left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return solve(n-1, m-1, grid);
}

//Appraoch 2: DP with memoization

int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int> > &dp)
{
    if(i==0 && j == 0)
        return grid[0][0];
    if(i < 0 || j < 0)
        return 1e9;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = grid[i][j] + solve(i-1, j, grid ,dp);
    int left = grid[i][j] + solve(i, j-1, grid, dp);
    return dp[i][j] = min(up , left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return solve(n-1, m-1, grid, dp);
}

//Appraoch 3: Dp with Tabulation
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
}

//Appraoch 4: Space optmized

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m,0);
    for(int i=0; i<n ; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) temp[j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=temp[j-1];
                else left += 1e9;
                
                temp[j] = min(up,left);
            }
        }
        prev=temp;
    }
    
    return prev[m-1];
}
