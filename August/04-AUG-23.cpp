class Solution{
public:
    void insertAtBottom(stack<int> &st,int ele) {
        if(st.empty()) {
            st.push(ele);
            return ;
        }
        
        int top=st.top();
        st.pop();
        insertAtBottom(st,ele);
        st.push(top);
    }
    
    void Reverse(stack<int> &st){
        if(st.empty()) return;
        
        int top=st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st,top);
    }
};