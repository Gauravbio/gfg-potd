class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<M;i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            
            adj[u].push_back({v,w});
        }
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> ans(N,1e9);
        ans[0]=0;
        
        while(!q.empty()) {
            auto front=q.front();
            int node=front.first;
            int w=front.second;
            q.pop();
            
            for(auto it: adj[node]) {
                if(ans[it.first]> it.second + w){
                    ans[it.first]=w+it.second;
                    q.push({it.first,it.second+w});
                }
            }
        }
        
        for(int i=0;i<N;i++) {
            if(ans[i]==1e9) ans[i]=-1;
        }
        
        return ans;
    }
};