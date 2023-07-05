class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        
        for(int i=0;i<n;i++) {
            arr[i]*=n;
        }
        
        for(int i=0;i<n;i++) {
            int index=0;
            if(arr[i]!=0) index=(arr[i]/n);
            int newEle=0;
            if(arr[index]!=0) newEle=(arr[index]/n);
            arr[i]+=newEle;
        }
        
        for(int i=0;i<n;i++) {
            arr[i]%=n;
        }
        
    }
};