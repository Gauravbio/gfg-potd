class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        int i=0;
        int j=m-1;
        long long ans=1e15;
        while(j<n) {
            ans=min(ans,a[j]-a[i]);
            j++;
            i++;
        }
        return ans;
    }   
};