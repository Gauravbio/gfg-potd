Node *removeDuplicates(Node *head)
{
 // your code goes here
 Node* node=head;
 while(node!=NULL) {
     Node* curr=node;
     node=node->next;
     while(node!=NULL && curr->data == node->data) {
         node=node->next;
     }
     
     curr->next=node;
 }
 
 return head;
}