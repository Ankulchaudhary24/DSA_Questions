/*

Given a binary tree with a value associated with each node,
we need to choose a subset of these nodes such that sum of chosen nodes is maximum
under a constraint that no two chosen node in subset should be directly connected that is,
if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.

*/

pair<int, int> solve(Node* root)
    {
        if(root == NULL)
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int, int> ans;
        ans.first = root->data+left.second+right.second;
        ans.second = max(left.first,left.second)+max(right.first,right.second);
        return ans;
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }

