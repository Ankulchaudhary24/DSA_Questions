/*
Given a Directed Acyclic Graph (DAG) with V
vertices and E edges, Find any Topological Sorting of that Graph.
*/
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    queue<int> q;
	    vector<int> ans;
	    
	    //Step 1: Finding the indegree of the nodes
	    for(int i = 0; i < V ; i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    //Step 2: Pushing the nodes with indegree 0 to the queue;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    //Step 3: Traversing the nodes till the queue is empty
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
