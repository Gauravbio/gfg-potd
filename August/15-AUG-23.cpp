class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int zero=0;
        int ones=0;
        for(int i=0;i<n;i++) {
            if(a[i]==1) ones++;
        }
        
        int ans=ones;
        for(int i=0;i<n;i++) {
            if(a[i]==0) zero++;
            else zero--;
            
            if(zero<0) zero=0;
            
            ans=max(ones+zero,ans);
        }
        
        return ans;
    }
};