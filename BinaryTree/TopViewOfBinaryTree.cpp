/*

Given below is a binary tree. The task is to print the top view of binary tree.
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
*/

 vector<int> topView(Node *root)
    {
         // Vector to store the nodes present in the Top view
        vector<int> ans;
    
       // If the root is null then simply return the answer
        if(root == NULL)
        return ans;
        
        //make a map that will store the mapping of the horizontal distance(hd)
        // with the first value found for that hd
        map<int,int> topNode;
        
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
            
            //check if the data for that hd is present or not, if not present than
            // insert it into the map
            if(topNode.find(hd) == topNode.end())
            topNode[hd]=frontNode->data;
            //Moving to the left subtree of the node
            if(frontNode->left)
               q.push(make_pair(frontNode->left,hd-1));
            
            //Going in the right subtree of the node
            // increasing the hd by 1
            if(frontNode->right)
               q.push(make_pair(frontNode->right,hd+1));
        }
        
        //Storing the top view nodes sorted out according the the hd from the map
        for(auto i : topNode){
            ans.push_back(i.second);
        }
        return ans;
    }
