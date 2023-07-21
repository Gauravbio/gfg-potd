class Solution
{
    private:
    struct node* rev(struct node *curr,struct node *limit) {
        if(curr==NULL) return NULL;
        
        struct node *tail=curr;
        struct node *prev=NULL;
        struct node *forward=NULL;
        
        while(curr!=limit) {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    public:
    struct node *reverse (struct node *head, int k)
    {   
        struct node *curr=head;
        struct node *prev=head;
        int node=0;
        struct node *ans=head;
        struct node *last=NULL;
        
        while(curr!=NULL){
            node++;
            curr=curr->next;
            if(node==k) {
                struct node *revHead=rev(prev,curr);
                if(last==NULL) ans=revHead;
                else {
                    last->next=revHead;
                }
                last=prev;
                prev=curr;
                node=0;
            }
        }
        
        if(last==NULL) return rev(prev,NULL);
        else last->next=rev(prev,NULL);
        return ans;
    }
};