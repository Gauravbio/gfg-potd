void printCorner(Node *root)
{

// Your code goes here
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int n=q.size();
        cout<<q.front()->data<<" ";
        if(n>1) cout<<q.back()->data<<" ";
        
        for(int i=0;i<n;i++) {
            auto front=q.front();
            q.pop();
            
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }

}