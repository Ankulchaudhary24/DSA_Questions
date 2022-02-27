/*** Introduction:

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, 
then print the later one in level traversal. For example, in the below diagram, 
3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

***/

//Writing only the functions
vector <int> bottomView(Node *root) {
       // Vector to store the nodes present in the bottom view
        vector<int> ans;
    
       // If the root is null then simply return the answer
        if(root == NULL)
        return ans;
        
        //make a map that will store the mapping of the horizontal distance(hd)
        // with the latest value found for that hd
        map<int,int> bottomNode;
        
        //queue is used to trverse the tree in the level order 
        queue< pair<Node*,int> > q;
        
        //push the root node in the queue
        q.push(make_pair(root,0));
        
        //Traverse the tree in level order
        while(!q.empty()){
            
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            bottomNode[hd]=frontNode->data;
            //Moving to the left subtree of the node
            if(frontNode->left)
               q.push(make_pair(frontNode->left,hd-1));
            
            //Going in the right subtree of the node
            // increasing the hd by 1
            if(frontNode->right)
               q.push(make_pair(frontNode->right,hd+1));
        }
        
        //Storing the Bottom nodes sorted out according the the hd from the map
        for(auto i : bottomNode){
            ans.push_back(i.second);
        }
        return ans;
    }
