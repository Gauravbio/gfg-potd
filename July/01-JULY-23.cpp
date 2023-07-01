class Solution {
  public:
    int setBits(int N) {
        int temp=N;
        int ans=0;
        while(temp>0) {
            int bit=temp&1;
            if(bit==1) ans+=1;
            temp>>=1;
        }
        
        return ans;
    }
};