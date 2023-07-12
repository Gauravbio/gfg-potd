class Solution{
    private:
    int mod=1e9+7;
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       if(R==1) return N%mod;
       int temp=(1ll*N*N)%mod;
       
       if(R&1) {
           return (1ll*N*power(temp,R/2)%mod);
       }
       else return (power(temp,R/2)%mod);
    }

};