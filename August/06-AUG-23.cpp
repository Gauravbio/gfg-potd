class Solution{
    public:
    //Complete this function
    
    void solve(vector<string> &ans,int index,string &s) {
        if(index<0) {
            ans.push_back(s);
            return ;
        }
        
        for(int i=index;i>=0;i--) {
            swap(s[index],s[i]);
            solve(ans,index-1,s);
            swap(s[index],s[i]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        int n=S.size();
        solve(ans,n-1,S);
        sort(ans.begin(),ans.end());
        return ans;
    }
};