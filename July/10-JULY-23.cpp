class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        
        for(int c=0;c<n;c++) {
            for(int r=c;r<n;r++) {
                swap(matrix[r][c],matrix[c][r]);
            }
        }
    }
};