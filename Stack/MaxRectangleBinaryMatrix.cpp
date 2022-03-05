/*

Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.

*/

vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
    
    //Function to find largest rectangular area possible in a given histogram.
    int getMaxArea(int v[], int n)
    {
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=v[i];
        }
        vector<int> next(n), prev(n);
        next = nextSmallerElement(arr,n);
        prev = prevSmallerElement(arr,n);
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int l = arr[i];
            if(next[i]==-1)
            next[i]=n;
            int b = next[i]-prev[i]-1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
     
    int maxArea(int M[MAX][MAX], int n, int m) {
        // compute area for first row
        int area = getMaxArea(M[0],m);
        for(int i=1;i<n;i++){
            for(int j =0;j<m;j++){
                if(M[i][j]!=0)
                M[i][j]+=M[i-1][j];
            }
            area = max(area,getMaxArea(M[i],m));
        }
        return area;
    }
