/*

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1).
Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while
value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.

*/

 bool possible(int x,int y,vector<vector<int>> m, vector<vector<int>> visited,int n )
    {
        if((x>=0 &&x<n) &&(y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0)
           return true;
        else
           return false;
    }
    
    void solve(vector<vector<int>> &m,int n, vector<string>&ans, int x, int y ,vector<vector<int>> &visited, string path)
    {
        if(x ==n-1 && y ==n-1)
        {
            ans.push_back(path);
            return;
        }
         visited[x][y]=1;
         
         int newx;
         int newy;
         //Down
         newx = x+1;
         newy = y;
         if(possible(newx,newy,m,visited,n))
         {
             path +='D';
             solve(m,n,ans,newx,newy,visited,path);
             path.pop_back();
         }
         
         //Left
         newx = x;
         newy = y-1;
         if(possible(newx,newy,m,visited,n))
         {
             path +='L';
             solve(m,n,ans,newx,newy,visited,path);
             path.pop_back();
         }
         //Right
         newx = x;
         newy = y+1;
         if(possible(newx,newy,m,visited,n))
         {
             path +='R';
             solve(m,n,ans,newx,newy,visited,path);
             path.pop_back();
         }
         //Up
         newx = x-1;
         newy = y;
         if(possible(newx,newy,m,visited,n))
         {
             path +='U';
             solve(m,n,ans,newx,newy,visited,path);
             path.pop_back();
         }
         
         visited[x][y]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0)
        return ans;
        int scrx = 0;
        int scry = 0;
        vector<vector<int>> visited(n,vector<int>(n,0));
        string path="";
        solve(m,n,ans,scrx,scry,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
