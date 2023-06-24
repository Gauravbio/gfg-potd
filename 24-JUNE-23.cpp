class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        string target=str.substr(0,k);
        int ans=0;
        for(int i=0;i<n;i++) {
            if(arr[i].size()>=k) {
                string temp=arr[i].substr(0,k);
                if(target==temp) ans++;
            }
        }
        
        return ans;
    }
};