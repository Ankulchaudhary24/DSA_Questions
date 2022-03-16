/*
Given a Binary search tree. Your task is to complete the function which
will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10
*/

vector<int> in;
    void inorder(Node* root, vector<int> &in){
        if(root==NULL)
            return;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    int kthLargest(Node *root, int K)
    {
        inorder(root, in);
        for(int i=in.size()-1; i>=0; i--){
            if(i==in.size()-K){
                return in[i];
            }
        }
    }
