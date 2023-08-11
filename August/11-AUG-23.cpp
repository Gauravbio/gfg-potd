class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<long long int> dp(sum+1,0);
        // return solve(coins,N,sum,0,dp);
        
        dp[0]=1;
        for(int coin=0;coin<N;coin++) {
            for(int i=1;i<=sum;i++) {
                if(i>=coins[coin]) dp[i]+=dp[i-coins[coin]];
            }
        }
        
        return dp[sum];
        
    }
};