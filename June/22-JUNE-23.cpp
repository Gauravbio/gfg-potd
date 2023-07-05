class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        int rup_5=0,rup_10=0;
        
        for(int i=0;i<n;i++) {
            if(bills[i]==5) rup_5++;
            else if(bills[i]==10) {
                if(rup_5==0) return 0;
                rup_5--;
                rup_10++;
            }
            else {
                if(rup_5 && rup_10) {
                    rup_10--,rup_5--;
                }
                else if(rup_5>=3) {
                    rup_5-=3;
                }
                else return 0;
            }
        }
        
        return 1;
    }
};