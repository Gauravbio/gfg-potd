class Solution {
    int mod=1e9+7;
  public:
    int sumOfNaturals(int n) {
        long long ans=n%mod;
        ans = (ans * (n+1))%mod;
        return (ans/2);
    }
};