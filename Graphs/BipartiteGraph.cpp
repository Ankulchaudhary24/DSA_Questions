/*
Given an adjacency list of a graph adj  of V
no. of vertices having 0 based index.
Check whether the graph is bipartite or not.

*/

//Appraoch 1: Using the BFS traversal
bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}

    bool isBipartite(int V, vector<int>adj[])
    {
	    int color[V];
        memset(color, -1, sizeof color); 
        for(int i = 0;i<V;i++) 
        {
            if(color[i] == -1) 
            {
                if(!bipartiteBfs(i, adj, color)) {
                     return false;
            }
        }
    }
    return true;
	}

//Approach 2: Using the DFS traversal
bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}
