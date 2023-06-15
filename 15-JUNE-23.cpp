class Solution {
    private:
    string dpApproach(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        string ans="";
        for(int i=0;i<n;i++) {
            int r=0,c=i;
            bool flag=1;
            while(c<n) {
                if(i==0) {
                    dp[r][c]=1;
                }
                else if(i==1 && s[r]==s[c]) {
                    dp[r][c]=1;
                }
                else {
                    if(s[r]==s[c] && dp[r+1][c-1]) {
                        dp[r][c]=1;
                    }
                }
                if(flag && dp[r][c]) {
                    ans=s.substr(r,c-r+1);
                    flag=0;
                }
                r++,c++;
            }
            
        }
        
        return ans;
    }
    
    string helper(string s,int start,int end,int n) {
        while(start>=0 && end<n) {
            if(s[start]!=s[end]) {
                break;
            }
            start--;
            end++;
        }
        
        return s.substr(start+1,end-start-1);
    }
    
    string optimisedApproach(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++) {
            string curr=helper(s,i,i,n);
            if(curr.size()>ans.size()) {
                ans=curr;
            }
            
            curr=helper(s,i,i+1,n);
            if(curr.size()>ans.size()) {
                ans=curr;
            }
        }
        return ans;
    }
  public:
    string longestPalin (string s) {
        // return dpApproach(s);
        return optimisedApproach(s);
    }
};