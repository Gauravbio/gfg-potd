class Solution{
public:
	bool isLarger(vector<int>& arr, int num[], int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] < num[i]) return false;
        if(arr[i] > num[i]) return true;
    }
    return false;
}

vector<int> generateNextPalindrome(int num[], int n) {
    vector<int> ans(n);
    int l = 0, r = n-1;
    
    while(r > l) {
        ans[r] = ans[l] = num[l];
        l++;
        r--;
    }
    
    
    ans[r] = num[r];
    if(isLarger(ans , num , n))    return ans;
    int carry = 1;
    
    if(n % 2 == 1) {
        ans[r]++;
        if(ans[r] < 10) return ans;
        ans[r] = 0;
        carry = 1;
        r--;
        l++;
    }
    
    
    while(r >= 0) {
        ans[r] += carry;
        ans[l] += carry;
        if(ans[r] < 10) return ans;
        ans[r] = ans[l] = 0;
        carry = 1;
        r--;
        l++;
    }
    
    
    if(carry == 1) {
        ans.insert(ans.begin() , 1);
        ans[ans.size() - 1] = 1;
    }
    
    return ans;
}

};