class Solution{
  public:
    /*You are required to complete below function */
    
    string add(string ans,string tmp){
        int i=0;
        int carry=0;
        string res;
        
        for( i=0;i<min(ans.size(),tmp.size());i++) {
            int a=ans[i]-'0';
            int b=tmp[i]-'0';
            
            int aux=a+b+carry;
            res.push_back((aux%10)+'0');
            carry=aux/10;
        }
        
        while(i<tmp.size()) {
            int a=tmp[i]-'0';
            
            int aux=a+carry;
            res.push_back((aux%10)+'0');
            carry=aux/10;
            i++;
        }
        
        while(i<ans.size()) {
            int a=ans[i]-'0';
            i++;
            
            int aux=a+carry;
            res.push_back((aux%10)+'0');
            carry=aux/10;
        }
        
        if(carry) res.push_back(carry+'0');
        return res;
    }
    
    bool checkMinus(string &s1,string &s2) {
        char ch1=s1[0];
        char ch2=s2[0];
        if(ch1=='-' && ch2=='-') {
            s1=s1.substr(1);
            s2=s2.substr(1);
            return 0;
        }
        else if(ch1=='-' || ch2=='-') {
            if(ch1=='-') {
                s1=s1.substr(1);
            }
            else s2=s2.substr(1);
            return 1;
        }
        return 0;
    }
    
    string multiplyStrings(string s1, string s2) {
       //Your code here
       vector<string> addition;
       bool minus= checkMinus(s1,s2);
       
       int s1_i=0,s2_i=0;
       while(s1_i<s1.size() && s1[s1_i]=='0') s1_i++;
       s1=s1.substr(s1_i);
       while(s2_i<s2.size() && s2[s2_i]=='0') s2_i++;
       s2=s2.substr(s2_i);
       
    //   cout<<s1<<" "<<s2<<endl;
       for(int i=s1.size()-1;i>=0;i--) {
           string tmp;
           for(int j=s1.size()-1;j>i;j--) tmp.push_back('0');
           int carry=0;
           for(int j=s2.size()-1;j>=0;j--) {
               int a=s1[i]-'0';
               int b=s2[j]-'0';
               
               int res=a*b;
               res+=carry;
                tmp.push_back((res%10)+'0');
               carry=res/10;
           }
           if(carry!=0) tmp.push_back(carry+'0');
           addition.push_back(tmp);
       }
       
       string ans;
       
       for(int i=0;i<s1.size();i++) {
           ans=add(ans,addition[i]);
       }
       if(minus) ans.push_back('-');
       reverse(ans.begin(),ans.end());
       
       return ans;
    }

};