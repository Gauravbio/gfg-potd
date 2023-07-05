class Solution{
    private:
    bool isHappy(int n) {
        int temp=n;
        while(temp>9) {
            int sum=0;
            
            while(temp) {
                int digit=temp%10;
                sum+=(digit*digit);
                temp/=10;
            }
            
            temp=sum;
        }
        
        if(temp==1 || temp==7) return 1;
        return 0;
    }
public:
    int nextHappy(int N){
        int next=N+1;
        while(true) {
            if(isHappy(next)) {
                return next;
            }
            next++;
        }
        
        return 0;
    }
};