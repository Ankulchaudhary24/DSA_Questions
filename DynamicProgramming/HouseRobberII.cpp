/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
*/

//Modified approach , same as the maximum sum of the without the adjacent element.
int rob1(vector<int>& arr) {
        int prev = arr[0];
        int prev2 =0;
        int n = arr.size();
        for(int i=1; i<n; i++){
            int pick = arr[i];
            if(i>1)
                pick += prev2;
            int nonPick = 0 + prev;
            
            int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev= cur_i;
            
        }
        return prev; 
    }
    
    int rob(vector<int>& arr) {
        vector<int> temp1, temp2;
        int n = arr.size();
        if(n ==1)
            return arr[0];
        for(int i=0;i< n;i++)
        {
            if(i != 0) temp1.push_back(arr[i]);
            if(i != n-1) temp2.push_back(arr[i]);
        }
        
        return max(rob1(temp1), rob1(temp2));
    }
