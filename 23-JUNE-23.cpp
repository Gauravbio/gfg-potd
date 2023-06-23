class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        int maxi=0;
        int count[26]={0};
        for(int i=0;i<n;i++) {
            count[tasks[i]-'A']++;
            maxi=max(maxi,count[tasks[i]-'A']);
        }
        
        int max_ele=0;
        for(int i=0;i<26;i++) {
            if(count[i]==maxi) max_ele++;
        }
        
        // cout<<maxi<<" "<<max_ele<<endl;
        return max((maxi-1)*(k+1)+max_ele,n);
    }
};