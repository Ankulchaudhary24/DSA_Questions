/*
Given a directed graph.
The task is to do Breadth First Traversal of this graph starting from 0.

Note: One can move from node u to node v only if there's an edge from u to v 
and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph.
Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

*/

//This Appraoch can only be used of the connected Graph 
//for the disconnected component add the extra for loop for checking whether all the
// nodes are visited or not
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int> vis(V,0);
       vector<int> ans;
       queue<int>q;
       q.push(0);
       while(!q.empty())
       {
           int td=q.front();
           ans.push_back(q.front());
           q.pop();
           for(auto x:adj[td])
           {
               if(!vis[x])
               {
                   vis[x]=1;
                   q.push(x);
               }
           }
       }
      return ans;
    }
