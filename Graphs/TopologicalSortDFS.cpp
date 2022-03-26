/*
Given a Directed Acyclic Graph (DAG) with V 
vertices and E edges, Find any Topological Sorting of that Graph.

*/

void findTopoSort(int node, vector<int> &vis, stack<int>& st,  vector<int> adj[])
	{
	    vis[node]=1;
	    for(auto it: adj[node])
	    {
	        if(vis[it]==0)
	        {
	            findTopoSort(it, vis, st, adj);
	        }
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	  stack<int> st; //Stack will store the topoligical sort of the graph
	  vector<int> vis(V,0);
	  for(int i=0;i<V;i++)
	  {
	      if(vis[i]==0)
	      {
	          findTopoSort(i, vis, st, adj);
	      }
	  }
	  
	  vector<int> ans;
	  while(!st.empty())
	  {
	      ans.push_back(st.top());
	      st.pop();
	  }
	  return ans;
	}

