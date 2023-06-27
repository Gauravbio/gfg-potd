class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int> s;
        while(head1!=NULL) {
            s.insert(head1->data);
            head1=head1->next;
        }
        
        while(head2!=NULL) {
            s.insert(head2->data);
            head2=head2->next;
        }
        
        struct Node *node=new Node(0);
        struct Node *ans=node;
        
        for(auto it: s) {
            struct Node *node1=new Node(it);
            node1->next=NULL;
            node->next=node1;
            node=node->next;
        }
        
        return ans->next;
    }
};