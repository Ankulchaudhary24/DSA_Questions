vector<int> inOrder(Node* root)
    {
        vector<int> ans;
        Node* pre, *curr;
        if(root == NULL)
        return ans;
        
        curr = root;
        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            
            else
            {
                //Finding the predecessor of the current Node
                pre = curr->left;
                while (pre->right != NULL && pre->right != curr)
                    pre = pre->right;
                    
                 /* Make current as the right child of its
               inorder predecessor */
                if (pre->right == NULL) {
                    pre->right = curr;
                    curr = curr->left;
                }
                
                /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
                else {
                    pre->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
