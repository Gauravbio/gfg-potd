class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        // for(int i=0;i<n;i++) cout<<updates[i]<<" ";
        for(int i=0;i<k;i++) {
            a[updates[i]-1]++;
        }
        
        int prev=0;
        for(int i=0;i<n;i++) {
            a[i]+=prev;
            prev=a[i];
        }
    }
};