class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* succ=NULL;
        while(root!=NULL) {
            if(root->data>x->data) {
                succ=root;
                root=root->left;
            }
            else {
                root=root->right;
            }
        }
        
        return succ;
    }
};