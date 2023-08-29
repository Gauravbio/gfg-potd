class Solution
{
    Node* reverse(Node* head) {
        Node* forward=NULL;
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL) {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node* revhead=reverse(head);
        int prev_max=0;
        Node* curr=revhead;
        Node* prev=NULL;
        Node* next=NULL;
        
        while(curr!=NULL) {
            next=curr->next;
            if(curr->data < prev_max) {
                prev->next=curr->next;
                curr->next=NULL;
            }
            else prev=curr;
            prev_max=max(prev_max,curr->data);
            curr=next;
        }
        
        return reverse(revhead);
    }
    
};