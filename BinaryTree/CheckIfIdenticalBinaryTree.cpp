/*

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

*/

bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p ==NULL && q == NULL)
            return true;
        
        if(p ==NULL && q != NULL)
            return false;
        
        if(p !=NULL && q == NULL)
            return false;
        
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        
        if((p->val == q->val)&&left&&right)
            return true;
        else
            return false;
    }
