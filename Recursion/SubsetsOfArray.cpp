/*

Given a set of positive integers, find all its subsets.

Example 1 :

Input : 
array = {1, 2, 3}
Output :
// this space denotes null element. 
1
1 2
1 2 3
1 3
2
2 3
3
Explanation: 
The following are the subsets 
of the array {1, 2, 3}.
Example 2 :

Input :
array = {1, 2}
Output :

1 
1 2
2

*/

//Recursive O(2^n) solution
 void solve(vector<int> arr,vector<int> output,int index,vector<vector<int> >&ans)
    {
        if(index >= arr.size())
        {
            ans.push_back(output);
            return;
        }
        
        //excluding the current element 
        solve(arr,output,index+1,ans);
        
        //Including the current element
        output.push_back(arr[index]);
        solve(arr,output,index+1,ans);
        
    }

    vector<vector<int> > subsets(vector<int>& arr)
    {
        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solve(arr,output,index,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
