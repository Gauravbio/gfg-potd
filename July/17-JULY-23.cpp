class Solution {
	public:
		string FirstNonRepeating(string s){
		    queue<char> q;
		    vector<int> count(26,0);
		    string ans="";
		    int n=s.size();
		    for(int i=0;i<n;i++) {
		        if(count[s[i]-'a']==0) q.push(s[i]);
		        count[s[i]-'a']++;
		        while(!q.empty() && count[q.front()-'a']>1) {
		            q.pop();
		        }
		        if(q.empty()) ans+='#';
		        else ans+=q.front();
		    }
		  //  cout<<endl;
		    
		    return ans;
		}

};