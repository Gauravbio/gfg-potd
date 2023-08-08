class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        for(int i=0;i<n;i++) {
            int gcd=__gcd(numerator[i],denominator[i]);
            
            numerator[i]/=gcd;
            denominator[i]/=gcd;
        }
        
        map<pair<int,int>,int> mp;
        int ans=0;
        
        for(int i=0;i<n;i++) {
            auto key=make_pair(denominator[i]-numerator[i],denominator[i]);
            if(mp.count(key)) {
                ans+=mp[key];
            }

            mp[{numerator[i],denominator[i]}]++;
        }
        
        return ans;
    }
};