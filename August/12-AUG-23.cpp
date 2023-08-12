class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> arr;
       arr.push_back(a[0]);
       
       for(int i=1;i<n;i++) {
           int index=(upper_bound(arr.begin(),arr.end(),a[i])-arr.begin());
           
           if(arr[index-1]!=a[i]) {
               
               if(index==arr.size()) {
                   arr.push_back(a[i]);
               }
               else {
                   arr[index]=a[i];
               }
           }
       }
       
       return arr.size();
    }
};