class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int> pre(n,0);
        vector<int> suf(n,0);
        
        pre[0]=arr[0];
        for(int i=1;i<n;i++) {
            pre[i]=min(pre[i-1],arr[i]);
        }
        
        suf[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--) {
            suf[i]=max(suf[i+1],arr[i]);
        }
        
        int i=0,j=0;
        int ans=0;
        while(i<=j && j<n) {
            if(pre[i]<=suf[j]) {
                ans=max(j-i,ans);
                // cout<<i<<" "<<j<<endl;
                j++;
            }
            else i++;
        }
        
        return ans;
    }

};