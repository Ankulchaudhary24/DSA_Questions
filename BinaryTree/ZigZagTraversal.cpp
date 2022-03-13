/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 

*/

 vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	if(root == NULL)
    	return ans;
    	
    	queue< Node *> q;
    	q.push(root);
    	
    	bool isLeftToRight = true;
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    vector<int> temp(size);
    	    
    	    for(int i =0; i<size;i++)
    	    {
    	        Node* front = q.front();
    	        q.pop();
    	        
    	        int index = isLeftToRight? i: size -i-1;
    	        temp[index]=front->data;
    	        
    	        if(front->left != NULL)
    	             q.push(front->left);
    	       
    	        if(front->right != NULL)
    	             q.push(front->right); 
    	    }
        
    	    isLeftToRight = !isLeftToRight;
        
    	    for(auto i : temp){
    	        ans.push_back(i);
    	    }
    	}
        return ans;	
    }
