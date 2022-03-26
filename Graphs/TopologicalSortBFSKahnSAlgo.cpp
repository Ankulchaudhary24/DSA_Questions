/*
Given a Directed Acyclic Graph (DAG) with V
vertices and E edges, Find any Topological Sorting of that Graph.
*/

//The Kahn's Algorithm can be used to check whether the graph contains cycle or not
// as the last if the ans array size is not equal to the nodes or the vertices
// then it means that the graph contains the cycle.
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
