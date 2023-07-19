class Solution{
    int lcs(string &s,int i,int j,vector<vector<int>> &dp) {
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int include=INT_MIN;
        if(s[i]==s[j]) {
            include=2+lcs(s,i+1,j-1,dp);
        }
        int exclude=max(lcs(s,i+1,j,dp),lcs(s,i,j-1,dp));
        
        return dp[i][j]= max(include,exclude);
    }
  public:
    int longestPalinSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return lcs(s,0,n-1,dp);
    }
};