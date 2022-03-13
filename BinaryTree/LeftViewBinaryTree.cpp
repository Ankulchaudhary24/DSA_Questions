/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

*/

void solve(Node* root, vector<int>&ans , int lvl){
    if(root == NULL){
        return ;
    }
    if(lvl == ans.size())
       ans.push_back(root->data);
    // if we are finding the left view then we will first traverse the left
    // subtree.
    // we will not be pushing the data for the same level node again becauase
    // the condition ans.size() == lvl cannot match as the ans.size() is already
    // greater than the level we will be present at that time.
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}
