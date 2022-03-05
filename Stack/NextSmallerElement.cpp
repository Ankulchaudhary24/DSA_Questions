/*

You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
If for any array element the next smaller element does not exist, you should print -1 for that array element.

Sample Input 1:
2
4
2 1 4 3
3
1 3 2
Sample Output 1:
1 -1 3 -1
-1 2 -1
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(st.top()>=curr)
               st.pop();
            ans[i]=st.top();
            st.push(curr);
        }
        return ans;
}
