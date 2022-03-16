/*

Given a Binary Search Tree and a target sum.
Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 

Example 1:

Input:
        2
      /   \
     1     3
sum = 5
Output: 1 
Explanation: 
Nodes with value 2 and 3 sum up to 5.
*/

void inorder(Node * root, vector<int> & in)
  {
      if(root == NULL)
      return;
      
      inorder(root->left,in);
      in.push_back(root->data);
      inorder(root->right,in);
      
  }
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
       vector<int> in;
       inorder(root,in);
       int s= 0;
       int e = in.size()-1;
       while(s<e)
       {
           int sum = in[s]+in[e];
           if(sum==target)
           return 1;
        
           else if(sum > target)
           e--;
           else
           s++;
       }
       return 0;
    }
