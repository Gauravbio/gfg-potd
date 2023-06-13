class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
        // brute force
	   sort(arr,arr+n);
	   vector<int> ans;
	    
	   for(int i=n-1;i>=n-k;i--) {
	       ans.push_back(arr[i]);
	   }
	   return ans;
	   
       // heap approach
	   vector<int> ans;
	   priority_queue<int,vector<int>,greater<int>> pq;
	   
	   for(int i=0;i<k;i++) pq.push(arr[i]);
	   
	   for(int i=k;i<n;i++) {
	       int mini=pq.top();
	       if(mini<arr[i]) {
	           pq.pop();
	           pq.push(arr[i]);
	       }
	   }
	   
	   for(int i=0;i<k;i++) {
	       ans.push_back(pq.top());
	       pq.pop();
	   }
	   reverse(ans.begin(),ans.end());
	   return ans;
	}

};