class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       vector<int> count(26,0);
       
       int n=S.size();
       for(int i=0;i<n;i++) {
           count[S[i]-'a']++;
       }
       
       for(int i=0;i<n;i++){
           if(count[S[i]-'a']==1) return S[i];
       }
       
       return '$';
       
    }

};