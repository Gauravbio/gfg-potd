class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        set<vector<int>> s;
        vector<vector<int>> ans;

        for(int i=0;i<row;i++) {
            vector<int> temp;
            for(int j=0;j<col;j++) temp.push_back(M[i][j]);
            if(s.find(temp)==s.end()) {
                s.insert(temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};