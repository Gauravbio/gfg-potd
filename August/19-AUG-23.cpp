class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        long long sum=0;
        int i=0,j=0;
        while(j<n) {
            sum+=arr[j];
            while(i<j && sum>s) {
                sum-=arr[i];
                i++;
            }
            
            if(sum==s) {
                return {i+1,j+1};
            }
            j++;
        }
        
        return {-1};
    }
};