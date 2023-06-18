class Solution {
  public:
    int distributeTicket(int n, int k) {
        int start=1;
        while(start<=n) {
            if(start+k>=n) return n;
            start+=k;
            if((n-k)<start) return start;
            n-=k;
        }
        return n;
    }
};