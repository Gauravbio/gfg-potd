class Solution {
  public:
    int matchGame(long long N) {
        if(N%5) return N%5;
        return -1;
    }
};