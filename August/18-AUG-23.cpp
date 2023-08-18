class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        ans.push_back(a[n-1]);
        int maxi_till_now=a[n-1];
        
        for(int i=n-2;i>=0;i--) {
            if(maxi_till_now<=a[i]) {
                ans.push_back(a[i]);
            }
            maxi_till_now=max(maxi_till_now,a[i]);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};