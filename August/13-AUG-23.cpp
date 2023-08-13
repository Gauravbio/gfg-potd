class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        long long mod=1000000007;
        if(n==1) return 0;
        if(n==2) return 1;
        
        long long first=0;
        long long second=1;
        
        for(int i=2;i<=n;i++) {
            long long temp=(first+second)%mod;
            first=second%mod;
            second=temp%mod;
        }
        
        return (second%mod);
    }
};