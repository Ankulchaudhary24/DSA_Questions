/*

Find the largest rectangular area possible in a given histogram where the largest
rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars
have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:
Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.

*/

vector<int> nextSmallerElement(vector<long long> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            long long curr = arr[i];
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
    
    vector<int> prevSmallerElement(vector<long long> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            long long curr = arr[i];
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
    long long getMaxArea(long long v[], int n)
    {
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=v[i];
        }
        vector<int> next(n), prev(n);
        next = nextSmallerElement(arr,n);
        prev = prevSmallerElement(arr,n);
        long long area = INT_MIN;
        for(int i=0;i<n;i++){
            long long l = arr[i];
            if(next[i]==-1)
            next[i]=n;
            long long b = next[i]-prev[i]-1;
            long long newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
