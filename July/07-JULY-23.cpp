class Solution
{
    //Function to merge the arrays.
    public static void merge(long arr1[], long arr2[], int n, int m) 
    {
        long arr[]=new long[n+m];
        int k=0;
        int i=0;int j=0;
        while(i<n && j<m) {
            if(arr1[i]>arr2[j]) {
                arr[k]=arr2[j++];
            }
            else {
                arr[k]=arr1[i++];
            }
            
            k++;
        }
        
        while(i<n) {
            arr[k++]=arr1[i++];
        }
        
        while(j<m) {
            arr[k++]=arr2[j++];
        }
        i=0;
        for(i=0;i<n;i++) {
            arr1[i]=arr[i];
        }
        
        for(;i<n+m;i++) {
            arr2[i-n]=arr[i];
        }
        
    }
}