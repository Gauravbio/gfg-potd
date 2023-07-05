class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int ans=0;
        
        for(int i=1;i<n;i++) {
            if(prices[i]>prices[i-1]) {
                ans+=(prices[i]-prices[i-1]);
            }
        }
        
        return ans;
    }
};