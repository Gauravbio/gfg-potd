class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> &vis,vector<int> adj[],int v,vector<int> &ans){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it: adj[node]) {
            if(!vis[it])
                dfs(it,vis,adj,v,ans);
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V,0);
        dfs(0,vis,adj,V,ans);
        return ans;
    }
};