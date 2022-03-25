/*
Given an undirected graph with V vertices and E edges,
check whether it contains any cycle or not. 
*/

//Appraoch 1: Using the BFS of the undirected graph
bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        queue<pair<int,int>> q;
        q.push({s,-1});
        
        visited[s] = 1;
        while(!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push({it,node});
                }
                else if(par != it)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkForCycle(i, V, adj, vis))
                    return true;
            }
        }
        return false;
    }

//Appraoch 2: Using the DFS of the undirected graph
bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1; 
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(checkForCycle(it, node, vis, adj)) 
                    return true; 
            }
            else if(it!=parent) 
                return true; 
        }
        
        return false; 
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                if(checkForCycle(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
