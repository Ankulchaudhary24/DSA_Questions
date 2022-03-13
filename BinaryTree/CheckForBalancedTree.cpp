/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 

*/

// Recursive O(n2) solution
int height(Node *root){
        if(root == NULL)
        return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left,right)+1;
        return ans;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL)
        return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        int h = (height(root->left)-height(root->right));
        if(left && right &&(abs(h)<=1))
        return true;
        else
        return false;
    }

//Recursive O(n) solution
pair<bool,int> isBalancedFast(Node *root){
        
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        int h = left.second-right.second;
        
        pair<bool , int> ans;
        if(left.first && right.first &&(abs(h)<=1))
        ans.first = true;
        else
        ans.first = false;
        
        ans.second = max(left.second, right.second)+1;
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
