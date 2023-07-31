class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> ans;
        q.push(0);
        vector<bool> vis(V,0);
        vis[0]=1;
        
        while(!q.empty()) {
            int front=q.front();
            ans.push_back(front);
            q.pop();
            
            for(auto node: adj[front]) {
                if(!vis[node]) {
                    q.push(node);
                    vis[node]=1;
                }
            }
        }
        
        return ans;
    }
};