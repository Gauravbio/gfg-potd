void inorder(vector<int> &in,struct Node *root) {
    if(root==NULL) return ;
    inorder(in,root->left);
    in.push_back(root->data);
    inorder(in,root->right);
}
float findMedian(struct Node *root)
{
      //Code here
      vector<int> in;
      inorder(in,root);
      
      int size=in.size();
      int mid= size/2;
      if(size%2==0) {
          return float(in[mid]+in[mid-1])/2;
      }
      return in[mid];
}