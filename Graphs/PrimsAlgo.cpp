/*
Given a weighted, undirected and connected graph of V 
vertices and E edges. The task is to find the sum of weights
of the edges of the Minimum Spanning Tree.
*/

//Appraoch 1: Brute force type using the >O(v2) time complexity where v is vertices

int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,INT_MAX); // Store the Weight from the choosed parent to node
        vector<int> parent(V,-1); // Store the parent node for the ith node
        vector<bool> mstSet(V,false); // store the information about node which are added in mst
        
        key[0]=0; //Choosing the first node as the source node
        
        for(int i =0; i<V-1; i++)
        {
            int mini = INT_MAX, u;
            
            for(int v = 0; v<V; v++)
            {
                if(mstSet[v] == false && key[v]<mini)
                {
                    mini = key[v];
                    u = v;
                }
            }
            
            mstSet[u] = true;
            for(auto it: adj[u])
            {
                int v = it[0];
                int weight = it[1];
                
                if(mstSet[v] == false && weight < key[v])
                {
                    parent[v]=u;
                    key[v] = weight;
                }
            }
        }
        
        int weightSum = 0;
        for(int i=0; i<V; i++)
        {
            weightSum +=key[i];
        }
        return weightSum;
    }

//Appraoch 2: everything is same as the above but instead of running the loop for finding the minimum
// we can simply use a min heap that will reduce the time complexity to O(v logv)
