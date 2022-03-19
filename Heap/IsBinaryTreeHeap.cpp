/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

*/
bool isCbt(struct Node* root, int i, int n)
    {
        if(root == NULL)
             return true;
        
        if(i >= n)
             return false;
        
        else
        {
            bool left = isCbt(root->left,2*i+1,n);
            bool right = isCbt(root->right,2*i+2, n);
            return left&&right;
        }
 
    } 
  
    bool isMaxOrder(Node* root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        
        else if(root->left != NULL && root->right == NULL)
            return root->data >= root->left->data;
        
        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            bool isMax =  (root->data>=root->left->data && root->data>=root->right->data);
            return left && right && isMax;
        }
            
    }
    
    int countNode(Node* root)
    {
        if(root == NULL)
        return 0;
        
        int ans = 1+countNode(root->left)+countNode(root->right);
        return ans;
    }
    
    bool isHeap(struct Node* tree) {
        int index =0;
        int totalCount = countNode(tree);
        if(isCbt(tree, index, totalCount) && isMaxOrder(tree))
        {
            return true;
        }
        else
          return false;
    }
