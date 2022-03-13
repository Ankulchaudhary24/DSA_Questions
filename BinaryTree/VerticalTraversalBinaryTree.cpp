/*

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
*/

vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int> > > nodes;
        queue< pair<Node *, pair<int, int> > > q;
        vector<int> ans;
        
        if(root == NULL)
        return ans;
        
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<Node*, pair<int,int> > p = q.front();
            q.pop();
            
            Node* frontNode = p.first;
            int hd = p.second.first;
            int lvl = p.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left != NULL)
            {
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            
             if(frontNode->right != NULL)
            {
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }
        
        for(auto i : nodes)
        {
            for(auto j: i.second)
            {
                for(auto k: j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        
        return ans;
    }
