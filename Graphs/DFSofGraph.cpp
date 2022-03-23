/*
Given a connected undirected graph.
Perform a Depth First Traversal of the graph.

Note: Use recursive approach to find the DFS traversal of 
the graph starting from the 0th vertex from left to right according to the graph..

*/
void dfs(int node,vector<int> &vis,vector<int> adj[], vector<int> &storeDfs )
    {
        storeDfs.push_back(node);
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,storeDfs);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> storeDfs;
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i] == 0)
            {
                dfs(i, visited, adj, storeDfs);
            }
        }
        return storeDfs;
    }
