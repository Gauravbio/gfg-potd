int height(Node* node) {
    return (node == NULL) ? 0 : node->height;
}
 
int getBalance(Node* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}
 
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
 
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
 
    return y;
}
 
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
 
Node* deleteNode(Node* root, int data)
{
    if (root == NULL)
        return root;
 
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = (root->left) ? root->left : root->right;
            
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else { 
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
 
    if (!root)
        return root;
 
    root->height = 1 + max(height(root->left), height(root->right));
 
    int balance = getBalance(root);
 
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
 
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
 
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}