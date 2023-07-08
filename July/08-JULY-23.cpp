class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
        for(int i=0;i<n-2;i++) {
            int low=i+1;
            int high=n-1;
            
            while(low<high) {
                int sum=arr[low]+arr[high]+arr[i];
                
                if(sum == 0) {
                    return 1;
                }
                else if( sum>0) {
                    high--;
                }
                else low++;
            }
        }
        
        return 0;
    }
};