Node *reverseLinkedListRec(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *l = reverseLinkedListRec(head->next);
  Node *tail = head->next;
  tail->next = head;
  head->next = NULL;
  return l;
}
Node *kReverse(Node * head, int k) {
    if (head == NULL || head->next == NULL || k < 2) {
      return head;
    }
	
	Node*temp=head,*phead=NULL;
	int pos=0;
	while(pos<k && head!=NULL){
		phead=head;
		head=head->next;
        pos++;
	}
	phead->next=NULL;
	Node *t=reverseLinkedListRec(temp);
	if(head!=NULL){
		Node*tail=kReverse(head,k );
		temp->next=tail;
	}
	return t;
}