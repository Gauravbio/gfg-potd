
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0;
        long product=1;
        
        for(int i=0,j=0;i<n;i++) {
            product*=a[i];
            
            while(j<=i && product>=k)  {
                product/=a[j];
                j++;
            }
            
            if(j>i) continue;
            
            ans+=(i-j+1);
        }
        
        return ans;
    }
};