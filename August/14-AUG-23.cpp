class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int temp=0;
        for(int num: nums) {
            temp^=num;
        }
        
        // taking last bit
        int lastBit=1;
        while(lastBit<temp) {
            lastBit<<=1;
        }
        
        if(lastBit!=temp) lastBit>>=1;
        
        
        //calc ans
        vector<int> ans(2,0);
        for(auto num: nums) {
            if(num & lastBit) {
                ans[0]^=num;
            }
            else ans[1]^=num;
        }
        
        if(ans[0]>ans[1]) swap(ans[0],ans[1]);
        return ans;
    }
};