class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        
        int factor=2;
        while((factor*factor)<=N) {
            if(N%factor == 0) {
                N/=factor;
            }
            else factor++;
        }
        
        return N;
    }
};