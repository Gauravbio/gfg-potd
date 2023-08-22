class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int maxi=0;
        vector<int> row(n,0),col(n,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                col[j] += matrix[i][j];
                row[i] += matrix[i][j];
                maxi=max(maxi,max(row[i],col[j]));
            }
        }

        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int op=min(maxi-row[i],maxi-col[j]);
                row[i]+=op;
                col[j]+=op;
                ans+=op;
            }
        }
        
        return ans;
    } 
};