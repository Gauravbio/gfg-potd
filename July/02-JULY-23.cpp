
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        
        for(int i=l-1;i<r;i++) {
            int y_mask= 1<<i;
            if(y_mask & y) {
                if(!(x & y_mask)) {
                    x |= y_mask;
                }
            }
        }
        
        return x;
    }
};