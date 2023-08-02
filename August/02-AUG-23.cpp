class Solution {
    class Value {
        public:
        int r;
        int c;
        int v;
        
        Value(int r,int c,int v) {
            this->r=r;
            this->c=c;
            this->v=v;
        }
        
    };
    
    bool  check(int r,int c,int n,int m) {
        if(r<0 || c<0 || r==n || c==m) return 0;
        return 1;
    }
    
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        queue<Value*> q;
        q.push(new Value(0,0,0));
        vector<vector<bool>> vis(N,vector<bool>(M,0));
        vis[0][0]=1;
        int step=0;
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        
        while(!q.empty()) {
            auto front=q.front();
            int r=front->r;
            int c=front->c;
            int step=front->v;
            q.pop();
            
            if(r==X && c==Y) return step;
            
            for(int i=0;i<4;i++) {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                
                if(check(nrow,ncol,N,M) && !vis[nrow][ncol] && A[nrow][ncol]==1) {
                    vis[nrow][ncol]=1;
                    q.push(new Value(nrow,ncol,step+1));
                }
            }
        }
        
        return -1;
    }
};