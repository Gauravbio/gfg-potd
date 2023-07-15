class Solution
{
    private:
    void solve(stack<int>&s,int ele, int mid) {
        if(s.empty()) return ;
        int top=s.top();
        s.pop();
        solve(s,ele+1,mid);
        if(ele!=mid) s.push(top);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        double temp=sizeOfStack+1;
        int mid= ceil(temp/2);
        solve(s,1,mid);
        
    }
};