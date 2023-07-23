class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int cnt[3]={0,0,0};
        Node* curr=head;
        
        while(curr!=NULL) {
            cnt[curr->data]++;
            curr=curr->next;
        }
        curr=head;
        
        for(int i=0;i<3;i++){
            while(curr!=NULL && cnt[i]--){
                curr->data=i;
                curr=curr->next;
            }
        }
        
        return head;;
        
    }
};