class Solution{
public:
    int mod=1e9+7;
    long long bin_expo(long long a,long long b) {
        if(b==1) return a;
        
        if(b&1) {
            return (a*bin_expo(a,b-1)%mod);
        }
        else {
            return (bin_expo(a*a%mod,b/2)%mod);
        }
    }
    
    int nCr(int n, int r){
        if(n<r) return 0;
        else if(n==r) return 1;
        
        long long newn=1;
        long long newr=1;
        int maxi=max(r,n-r);
        int mini=min(r,n-r);
        
        for(int i=n;i>maxi;i--) {
            newn=(newn * i)%mod;
        }
        
        for(int i=mini;i>0;i--) {
            newr=(newr*i)%mod;
        }
        
        
        long long r_inv= bin_expo(newr,mod-2);
        return (r_inv*newn)%mod;
    }
};