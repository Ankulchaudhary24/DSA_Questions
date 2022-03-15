/*
Given a binary tree and a node called target.
Find the minimum time required to burn the complete binary tree if the target is set on fire.
It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

*/
 Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent)
    {
        Node* res = NULL;
        queue<Node* > q;
        q.push(root);
        nodeToParent[root]=NULL;
        
        while(!q.empty())
        {
          Node *frontNode = q.front();
          q.pop();
          
          if(frontNode->data == target)
          {
              res = frontNode;
          }
          
          if(frontNode->left!=NULL)
          {
              nodeToParent[frontNode->left]=frontNode;
              q.push(frontNode->left);
          }
          
          if(frontNode->right!=NULL)
          {
              nodeToParent[frontNode->right]=frontNode;
              q.push(frontNode->right);
          }
        }
        return res;
    }
   
    int burnTree(Node* root, map<Node*, Node*> nodeToParent)
    {
        map<Node* , bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root]=true;
        
        int ans =0;
        while(!q.empty())
        {
            int size = q.size();
            bool flag = 0;
            for(int i =0;i<size; i++)
            {
                Node* front = q.front();
                q.pop();
                
                if(front->left!=NULL && !visited[front->left])
                {
                    flag = 1;
                    visited[front->left]=true;
                    q.push(front->left);
                }
                
                if(front->right!=NULL && !visited[front->right])
                {
                    flag = 1;
                    visited[front->right]=true;
                    q.push(front->right);
                }
                
                if(nodeToParent[front]!=NULL && !visited[nodeToParent[front]])
                {
                    flag = 1;
                    visited[nodeToParent[front]]=true;
                    q.push(nodeToParent[front]);
                }
            }
            if(flag)
            ans++;
        }
        return ans;
        
    }
    
    int minTime(Node* root, int target) 
    {
       int ans =0;
       map<Node*, Node*> nodeToParent;
       Node* targetNode = createParentMapping(root, target, nodeToParent);
       
       ans=burnTree(targetNode, nodeToParent);
       
       return ans;
    }
