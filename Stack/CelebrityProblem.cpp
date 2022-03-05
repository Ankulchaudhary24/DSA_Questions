/*

A celebrity is a person who is known to all but does not know anyone at a party.
If you go to a party of N people, find if there is a celebrity in the party or not.

A square NxN matrix M[][] is used to represent people at the party such that if an element
of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

Note: Follow 0 based indexing.

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.

*/

//Stack Based Appraoch
int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++)
        st.push(i);
        while(st.size()!=1){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if(m[first][second]==1)
               {
                   st.push(second);
               }
            else
               st.push(first);
        }
        
        int r = st.top();
        for(int i=0;i<n;i++){
            if(r!=i){
                if(m[r][i]==1||!m[i][r]) //checking all row element should be 0 and all column element except where row = column should be 1
                return -1;
            }
        }
        return r;
    }


//Two PointerApproach
int celebrity(vector<vector<int> >& m, int n) 
    {
        int i=0,j=n-1;
        int ans=-1;
        while(i<j) m[i][j]?i++:j--;
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
                if(m[i][j]||!m[j][i]) return -1; //checking all row element should be 0 and all column element except where row = column should be 1
            }
        }
        return i;
    }
