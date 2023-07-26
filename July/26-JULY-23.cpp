int solve(Node *root, int k, int node,vector<int> &ancestor) {
    if(root==NULL) return -1;
    
    if(root->data==node) {
        int n=ancestor.size();
        if(n>=k) {
            return ancestor[n-k];
        }
        return -1;
    }
    
    ancestor.push_back(root->data);
    int left=solve(root->left,k,node,ancestor);
    int right=solve(root->right,k,node,ancestor);
    ancestor.pop_back();
    
    if(left!=-1)return left;
    return right;
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> ancestor;
    return solve(root,k,node,ancestor);
}