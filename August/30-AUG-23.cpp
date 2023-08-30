Node* deleteNode(Node *head,int x)
{
    //Your code here
    if(x==1) return head->next;
    Node* curr=head->next;
    Node* prev=head;
    int counter=2;
    
    while(curr!=NULL) {
        if(counter==x) {
            prev->next=curr->next;
            curr->next=NULL;
            break;
        }
        counter++;
        prev=curr;
        curr=curr->next;
    }
    return head;
}