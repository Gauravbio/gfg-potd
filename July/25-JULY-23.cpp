vector<int> findSpiral(Node *root)
{
    int lvl=1;
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    
    while(!q.empty()) {
        int size=q.size();
        int start=ans.size();

        for(int i=0;i<size;i++) {
            Node* front=q.front();
            ans.push_back(front->data);
            q.pop();
            if(front->left)  q.push(front->left);
            if(front->right) q.push(front->right);
        }
        
        if(lvl&1) {
               reverse(ans.begin()+start,ans.end());
        }
        lvl++;
    }
    
    return ans;
}