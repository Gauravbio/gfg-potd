class Solution
{
public:
    int getCount(Node *root, int k)
    {
        //code here
        int leaf=0;
        int budget=k;
        queue<pair<Node*,int>> q;
        
        q.push({root,1});
        
        while(!q.empty() && budget) {
            auto front=q.front();
            Node* node=front.first;
            int lvl=front.second;
            q.pop();
            
            if(node->left==NULL && node->right==NULL) {
                if(budget>=lvl) leaf++;
                budget=max(0,budget-lvl);
                continue;
            }
            
            if(node->left) 
                q.push({node->left,lvl+1});
            if(node->right) q.push({node->right,lvl+1});
        }
        
        return leaf;
    }
};