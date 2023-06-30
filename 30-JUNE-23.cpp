// C++ Code
class Solution{
public:	
		
	int isDivisible(string s){
	    long long rem=0;
	    int n=s.size();
	    
	    for(int i=0;i<n;i++) {
	        if(s[i]=='1') {
    	        if(i&1) {
    	            rem+=2;
    	        }    
    	        else rem+=1;
	        }
	    }
	    
	    rem%=3;
	    if(rem) return 0;
	    return 1;
	}

};