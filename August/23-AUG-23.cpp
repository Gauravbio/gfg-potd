class Solution {
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    
    bool check(int r,int c,int m,int n) {
        if(r<0 || c<0 || r==m || c==n) return 0;
        return 1;
    }
    
    bool dfs(int r,int c,int m,int n,string &word,vector<vector<char>> &grid) {
        
        for(int i=0;i<8;i++) {
            int x=r;
            int y=c;
            bool found=1;
            
            for(int j=0;j<word.size();j++) {
                if(!check(x,y,m,n) || word[j]!=grid[x][y]) {
                    found=0;
                    break;
                }
                x=dx[i]+x;
                y=dy[i]+y;
            }
            if(found) return 1;
        }
        
        return 0;
    }
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int m=grid.size();
	    int n=grid[0].size();
	    vector<vector<int>> ans;
	    
	    for(int i=0;i<m;i++) {
	        for(int j=0;j<n;j++) {
	            if(dfs(i,j,m,n,word,grid)) {
	                ans.push_back({i,j});
	            }
	        }
	    }
	    
	    return ans;
	}
};