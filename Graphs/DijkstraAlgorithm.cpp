/*
Given a weighted, undirected and connected graph of V vertices
and E edges, Find the shortest distance of all the vertex's from the source vertex S.

Note: The Graph doesn't contain any negative weight cycle.
*/

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
    vector<int> distTo(V,INT_MAX); 	
    distTo[S] = 0;
    pq.push(make_pair(0,S));	// (dist,from)

    while( !pq.empty() ){
      int dist = pq.top().first;
      int prev = pq.top().second;
      pq.pop();

      vector<vector<int> >::iterator it;
      for( it = adj[prev].begin() ; it != adj[prev].end() ; it++){
        int next = it[0][0];
        int nextDist = it[0][1];
        if( distTo[next] > distTo[prev] + nextDist){
          distTo[next] = distTo[prev] + nextDist;
          pq.push(make_pair(distTo[next], next));
        }
      }

    }
	return distTo;
   }
