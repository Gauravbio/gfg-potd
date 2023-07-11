class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int top=0,bottom=n-1;
 		int left=0,right=m-1;
 		int ele=0;
 		
 		while(top<=bottom && left<=right) {
 		    for(int i=left;i<=right;i++) {
 		        ele++;
 		        if(ele==k) return a[top][i];
 		    }
 		    
 		    top++;
 		    for(int i=top;i<=bottom;i++) {
 		        ele++;
 		        if(ele==k) return a[i][right];
 		    }
 		    
 		    right--;
 		    for(int i=right;i>=left;i--) {
 		        ele++;
 		        if(ele==k) return a[bottom][i];
 		    }
 		    
 		    bottom--;
 		    for(int i=bottom;i>=top;i--) {
 		        ele++;
 		        if(ele==k) return a[i][left];
 		    }
 		    
 		    left++;
 		}
    }
};