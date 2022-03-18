/*

Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
   */

class info{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
    
};
class Solution{
    public:
    info solve(Node* root, int& maxSize)
    {
        //base case
        if(root == NULL)
        {
           return {INT_MIN, INT_MAX, true, 0 };
        }
        
        info left = solve(root->left, maxSize);
        info right = solve(root->right, maxSize);
        
        info ans;
        bool rootIsBST = root->data>left.maxi && root->data<right.mini;
        if(rootIsBST && left.isBst && right.isBst){
            ans.isBst = true;
            ans.maxi = max(right.maxi, root->data);
            ans.mini = min(left.mini, root->data);
            ans.size = left.size+right.size+1;
            maxSize = max(maxSize, ans.size);
        }
        else
            ans.isBst = false;
        
        return ans;
    }
    
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	int maxSize = 0;
    	info temp = solve(root, maxSize);
    	return maxSize;
    }
};
