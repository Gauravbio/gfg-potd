class Solution{
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    
    bool check(int r,int c,int n,int m) {
        if(r<0 || c<0 || c==m || r==n) return 0;
        return 1;
    }
    
    void dfs(vector<vector<char>> &mat,int n,int m,vector<vector<bool>> &vis,int row,int col,
    vector<vector<char>> &ans) {
        
        vis[row][col]=1;
        ans[row][col]='O';
        
        for(int i=0;i<4;i++) {
            int nrow=dx[i]+row;
            int ncol=dy[i]+col;
            
            if(check(nrow,ncol,n,m) && mat[nrow][ncol]=='O' && !vis[nrow][ncol]) {
                dfs(mat,n,m,vis,nrow,ncol,ans);
            }
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> vis(n,vector<bool> (m,0));
        vector<vector<char>> ans(n,vector<char> (m,'X'));
        
        // first and last columns
        for(int i=0;i<n;i++) {
            if(mat[i][0]=='O' && !vis[i][0]) {
                dfs(mat,n,m,vis,i,0,ans);
            }
            
            if(mat[i][m-1]=='O' && !vis[i][m-1]) {
                dfs(mat,n,m,vis,i,m-1,ans);
            }
        }
        
        // first and last row
        for(int i=0;i<m;i++) {
            if(mat[0][i]=='O' && !vis[0][i]) {
                dfs(mat,n,m,vis,0,i,ans);
            }
            if(mat[n-1][i]=='O' && !vis[n-1][i]) {
                dfs(mat,n,m,vis,n-1,i,ans);
            }
        }
        
        return ans;
    }
};