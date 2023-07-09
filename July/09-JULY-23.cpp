class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int i=0;
        int pos_index=0,j=0;
        
        while(j<n) {
            if(arr[j]>0) {
                swap(arr[j],arr[pos_index++]);
            }
            j++;
        }

        while(i<pos_index) {
            if((arr[i]-1)!=i && arr[i]<=pos_index && arr[i]!=arr[arr[i]-1]) {
                swap(arr[i],arr[arr[i]-1]);
            }
            else i++;
        }
        
        for(i=0;i<pos_index;i++) {
            if(i!=(arr[i]-1)) return (i+1);
        }
        
        return pos_index+1;
    } 
};