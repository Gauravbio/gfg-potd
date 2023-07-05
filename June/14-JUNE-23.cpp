class Solution {
  public:
    long long maxDiamonds(int a[], int n, int k) {
        
        
        priority_queue<int> pq;
        
        for(int i=0;i<n;i++) {
            pq.push(a[i]);
        }
        
        long long i=0;long long ans=0;
        while(i<k) {
            int top=pq.top();
            ans+=top;
            pq.pop();
            pq.push(top/2);
            i++;
        }
        
        return ans;
    }
};