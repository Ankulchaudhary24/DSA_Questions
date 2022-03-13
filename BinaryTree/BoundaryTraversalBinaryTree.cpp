/*

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- 
the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root.
The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree.
Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

Example 2:

Input:
            1
           / 
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8
*/

void leftPart(Node* root, vector<int> &ans)
    {
        if(root==NULL || (root->left==NULL&& root->right==NULL))
           return;
         
        ans.push_back(root->data);
        if(root->left != NULL)
           leftPart(root->left,ans);
        else
           leftPart(root->right,ans);
    }
    
    
    void leafNodes(Node* root,vector<int> &ans )
    {
       if(root == NULL)
       return;
       
       if(root->left==NULL&& root->right==NULL)
       ans.push_back(root->data);
       
       leafNodes(root->left,ans);
       leafNodes(root->right,ans);
    }
    
    void rightPart(Node*root, vector<int> & ans)
    {
        if(root == NULL)
        return;
        
        if(root->left==NULL&& root->right==NULL)
        return;
        
        if(root->right != NULL)
            rightPart(root->right,ans);
        else
            rightPart(root->left,ans);
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        if(root == NULL)
        return ans;
        
        ans.push_back(root->data);
        leftPart(root->left,ans);
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
        rightPart(root->right,ans);
        return ans;
    }
