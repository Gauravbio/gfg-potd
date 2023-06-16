class Solution {
    private:
    long long solve(unordered_map<int,vector<int>> &mp,vector<int> &types,int currPos,int index
    , vector<vector<long long>> &dp,int flag){
        if(index==types.size()) {
            return 0;
        }
        if(dp[index][flag]!=-1) return dp[index][flag];
        
        int start=mp[types[index]][0];
        int end=mp[types[index]][1];
        
        long long left=(1ll*abs(currPos-start)+abs(start-end)+solve(mp,types,end,index+1,dp,0));
        if(index==types.size()-1) left+=abs(end);
        long long right=(1ll*abs(currPos-end)+ abs(end-start)) +solve(mp,types,start,index+1,dp,1);
        if(index==types.size()-1) right+=abs(start);
        dp[index][flag]=min(left,right);
        return min(left,right);
    }
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        unordered_map<int,vector<int>> mp;
        int type=0;
        for(int i=0;i<n;i++) {
            if(mp.find(types[i])!=mp.end()) {
                mp[types[i]][0]=min(locations[i],mp[types[i]][0]);
                mp[types[i]][1]=max(locations[i],mp[types[i]][1]);
            }
            else {
                mp[types[i]].push_back(locations[i]);
                mp[types[i]].push_back(locations[i]);
                
            }
            type=max(type,types[i]);
        }
        
        
        vector<int> temp;
        for(int i=0;i<=type;i++) {
            if(mp.find(i)!=mp.end()) temp.push_back(i);
        }
        
        // for(auto it: mp) {
        //     cout<<it.first<<" -> "<<it.second[0]<<" "<<it.second[1]<<endl;
        // }
        vector<vector<long long>> dp(type+1,vector<long long>(2,-1));
        return solve(mp,temp,0,0,dp,0);
    }
};