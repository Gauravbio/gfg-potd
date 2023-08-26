class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int> mp;
        int start=0;
        int ans=-1;
        
        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
            while(mp.size()>k) {
                mp[s[start]]--;
                if(mp[s[start]]==0) mp.erase(s[start]);
                start++;
            }
            if(mp.size()==k)ans=max(ans,(i-start+1));
        }
        
        return ans;
    }
};