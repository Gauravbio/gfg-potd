class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int lower=lower_bound(arr,arr+n,x)-arr;
	    
	    if(lower==n || arr[lower]!=x) return 0;
	    int upper=upper_bound(arr,arr+n,x)-arr;
	    int ans=(upper-lower);
	    return ans;
	}
};