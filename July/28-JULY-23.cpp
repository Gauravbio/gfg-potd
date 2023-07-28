
//O(Height of tree)
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            while(root!=NULL) {
                if(root->data>n1 && root->data>n2) {
                    root=root->left;
                }
                else if(root->data<n1 && root->data<n2) {
                    root=root->right;
                }
                else break;
            }
            
            return root;
        }

};

// O(n)
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            if(root==NULL) return NULL;
            if(root->data==n1) return root;
            if(root->data==n2) return root;
            
            Node* left=LCA(root->left,n1,n2);
            Node* right=LCA(root->right,n1,n2);
            
            if(left==NULL) return right;
            if(right==NULL) return left;
            
            return root;
        }

};