/*
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.


Example 1:

Input:      
Tree = 
          1                               
        /   \                          
       2     3
K = 3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
Example 2:

Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 8
Explanation:
The following paths sum to K.  
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 
*/

void solve(Node* root,int &cnt, vector<int> path, int k)
    {
        if(root == NULL)
        return;
        
        path.push_back(root->data);
        
        solve(root->left, cnt, path, k);
        solve(root->right, cnt, path, k);
        
        int size = path.size();
        int sum = 0;
        for(int i=size-1;i>=0;i--){
            sum += path[i];
            if(sum ==k)
            cnt++;
        }
        
        path.pop_back();
    }
    
    int sumK(Node *root,int k)
    {
        vector<int> paths;
        int cnt =0;
        solve(root, cnt, paths,k);
        return cnt;
    }
