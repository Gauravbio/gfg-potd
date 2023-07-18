class Solution {
    int n;
	public:
	    int solve(int i,int j,string &str,vector<vector<int>> &dp){
	        if(j==n) return 0;
	        if(dp[i][j]!=-1) return dp[i][j];
	        
	        int include=0;
	        if(i!=j && str[i]==str[j]) {
	            include=1+solve(i+1,j+1,str,dp);
	        }
	        
	        int exclude=solve(i,j+1,str,dp);
	        if(i<j){
	            exclude=max(solve(i+1,j,str,dp),exclude);
	        }
	        
	        return dp[i][j]=max(include,exclude);
	    }
		int LongestRepeatingSubsequence(string str){
		    n=str.size();
		    vector<vector<int>> dp(n,vector<int> (n,-1));
		    return solve(0,0,str,dp);
		}

};