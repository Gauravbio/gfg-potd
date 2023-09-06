class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node,vector<int> &vis,vector<int>adj[]) {
        vis[node]=1;
        for(auto nbr:adj[node]) {
            if(!vis[nbr])
                dfs(nbr,vis,adj);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> vis(V,0);
	    int lastNode=-1;
	    
	    for(int i=0;i<V;i++) {
	        if(!vis[i]) {
	            dfs(i,vis,adj);
	            lastNode=i;
	        }
	    }
	    
	    for(int i=0;i<V;i++) vis[i]=0;
	    
	    dfs(lastNode,vis,adj);
	    
	    for(int i=0;i<V;i++) {
	        if(!vis[i]) return -1;
	    }
	    
	    return lastNode;
	}

};