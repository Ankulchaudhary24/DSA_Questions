/*

Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
*/

vector<int> diagonal(Node *root)
{
   queue<Node *> q;
   vector<int > ans;
   
   if(root == NULL)
   {
       return ans;
   }
   
   q.push(root);
   
   while(!q.empty())
   {
       Node* t = q.front();
       q.pop();
       
       while(t)
       {
            if(t->left)
              q.push(t->left);
             
             ans.push_back(t->data);
             
             t = t->right;
       }
   }
   return ans;
}
