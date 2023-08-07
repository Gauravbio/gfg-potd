class Solution 
{
    public:
    
    bool isPossible(int num,int grid[N][N],int r,int c) {
        for(int i=0;i<9;i++) {
            if(grid[i][c]==num || grid[r][i]==num) return 0;
        }
        
        int sub_row=(r/3)*3;
        int sub_col=(c/3)*3;
        // cout<<sub_row<<" "<<sub_col<<endl;
        
        for(int i=sub_row;i<(sub_row+3);i++) {
            for(int j=sub_col;j<(sub_col+3);j++) {
                if(grid[i][j]==num) return 0;
            }
        }
        
        return 1;
    }
    //Function to find a solved Sudoku. 
    bool solve(int grid[N][N],int row,int col) {
        if(row==N) return true;
        
        int ncol=(col==8 ? 0: col+1);
        int nrow=(col==8? row+1: row);
        
        if(grid[row][col]==0) {
            for(int num=1;num<=9;num++) {
                if(grid[row][col]==0 && isPossible(num,grid,row,col)) {
                    grid[row][col]=num;
                    if(solve(grid,nrow,ncol))
                        return true;
                    grid[row][col]=0;
                }
            }
        }
        else {
            if(solve(grid,nrow,ncol)) return true;
        }
        
        return false;
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        solve(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};