class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        vector<int> count(1e4+1,0);
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL) {
            count[curr->data]++;
            if(count[curr->data]>1) {
                prev->next=curr->next;
                curr->next=NULL;
                delete curr;
                curr=prev->next;
            }
            else {
                prev=curr;
                curr=curr->next;
            }
        }
        
        return head;
    }
};