class Solution
{
    int mod=1e9+7;
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        vector<long long> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++) {
                dp[i] += ((dp[j]*dp[i-j-1])%mod);
                dp[i]%=mod;
            }
        }
        
        return dp[n];
    }
};