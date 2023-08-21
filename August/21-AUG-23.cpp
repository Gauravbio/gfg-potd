class Solution {
    bool check(int r,int c,int m,int n) {
        if(r<0 || r==m || c<0 || c==n) return 0;
        return 1;
    }
    bool count(int i,int j,int m,int n,vector<vector<int> >& matrix) {
        int ans=0;
        
        if(check(i-1,j-1,m,n) && matrix[i-1][j-1]==0) ans++;
        if(check(i-1,j,m,n) && matrix[i-1][j]==0) ans++;
        if(check(i-1,j+1,m,n) && matrix[i-1][j+1]==0) ans++;
        
        if(check(i,j-1,m,n) && matrix[i][j-1]==0) ans++;
        if(check(i,j+1,m,n) && matrix[i][j+1]==0) ans++;
        
        if(check(i+1,j-1,m,n) && matrix[i+1][j-1]==0) ans++;
        if(check(i+1,j,m,n) && matrix[i+1][j]==0) ans++;
        if(check(i+1,j+1,m,n) && matrix[i+1][j+1]==0) ans++;
        
        if(ans&1 || ans==0) return 0;
        return 1;
    }
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] && count(i,j,m,n,matrix)) ans++;
            }
        }
        
        return ans;
    }
};