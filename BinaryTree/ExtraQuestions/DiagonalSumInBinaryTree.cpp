/*
Consider Red lines of slope -1 passing between nodes (in following diagram).
The diagonal sum in a binary tree is the sum of all node’s data
lying between these lines. Given a Binary Tree of size N, print all diagonal sums.
Example 1:

Input:
         4
       /   \
      1     3
           /
          3
Output: 7 4 
Example 2:

Input:
           10
         /    \
        8      2
       / \    /
      3   5  2
Output: 12 15 3

*/

vector <int> diagonalSum(Node* root) {
    vector<int>v;
   if(!root) return {};
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       int n=q.size();
       int sum=0;
       for(int i=0;i<n;i++)
       {
           Node *t=q.front();q.pop();
           
           while(t)
           {   
               sum+=t->data;
               if(t->left) q.push(t->left);
               t=t->right;
           }
       }
       v.push_back(sum);
   }
   return v;
}
