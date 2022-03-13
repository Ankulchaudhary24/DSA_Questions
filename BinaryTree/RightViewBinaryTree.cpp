/*

Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
*/

 void solve(Node *root , vector<int>& ans, int lvl){
        if(root ==NULL)
        return;
        // for reference check the leeft view of the binary tree
        if(lvl == ans.size())
        ans.push_back(root->data);
        
        solve(root->right,ans,lvl+1);
        solve(root->left,ans,lvl+1);
    }
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }
