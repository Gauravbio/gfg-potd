class Solution{
  public:
    int solve(int *price,int n,vector<int> &dp) {
        if(n<=0) return 0;
        if(n==1) return price[0];
        if(dp[n-1]!=-1) return dp[n-1];
        
        int ans=0;
        for(int i=0;i<n;i++) {
            ans=max(ans,price[i]+solve(price,n-i-1,dp));
        }
        dp[n-1]=ans;
        return ans;
    }
    int cutRod(int price[], int n) {
        vector<int> dp(n,-1);
        return solve(price,n,dp);
    }
};