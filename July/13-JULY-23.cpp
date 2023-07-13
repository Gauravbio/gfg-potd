class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int> count;
        
        for(int i=0;i<n;i++) {
            count[arr[i]]++;
        }
        
        vector<int> temp(n+1,0);
        
        for(auto it: count) {
            temp[it.second]++;
            if(temp[it.second]>1) return 0;
        }
        
        return 1;
    }
};