class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high) return ;
        
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       
       int start=low,end=high-1;
       int it=low;
       while(start<=end && it<high) {
           if(arr[it]<arr[high]) {
               swap(arr[it],arr[start]);
               start++;
               it++;
           }
           else {
               swap(arr[it],arr[end]);
               end--;
           }
       }
       swap(arr[high],arr[start]);
       
       return start;
    }
};