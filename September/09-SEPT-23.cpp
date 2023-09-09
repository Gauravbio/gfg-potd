class Solution
{
    public:
    int kthLargest(Node *root, int &k)
    {
        //Your code here
        if(root==NULL) return -1;
        
        // if(k==0) return root->data;
        
        int right = kthLargest(root->right,k);
        if(right!=-1) return right;
        k--;
        if(k==0) return root->data;
        
        
        int left = kthLargest(root->left,k);
        
        return left;
    }
};