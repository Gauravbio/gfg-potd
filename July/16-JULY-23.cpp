class Solution
{
    void reverse(queue<int> &q) {
        if(q.empty()) return ;
        
        int front=q.front();
        q.pop();
        
        reverse(q);
        q.push(front);
    }
    public:
    queue<int> rev(queue<int> q)
    {
        reverse(q);
        return q;
    }
};