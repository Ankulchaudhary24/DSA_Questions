/*

Given a binary tree, flatten it into linked list in-place.
Usage of auxiliary data structure is not allowed.
After flattening, left of each node should point to NULL and right should contain next node in preorder.

Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
Example 2:

Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5  
Explanation : 
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.
*/

void flatten(Node *root)
    {
        Node* pre, *curr;
        if(root == NULL)
        return ;
        
        curr = root;
        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                curr = curr->right;
            }
            
            else
            {
                //Finding the predecessor of the current Node
                pre = curr->left;
                while (pre->right != NULL && pre->right != curr)
                    pre = pre->right;
                    
                 /* Make current->right as the right child of its
               inorder predecessor */
                if (pre->right == NULL) {
                    pre->right = curr->right;
                    curr->right = curr->left;
                    curr->left = NULL;
                }
            
            }
        }
    }
