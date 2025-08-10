int le(Node* head){
	int length=0;
        while (head->next != NULL) {
          head = head->next;
          length++;
        }
		return ++length;
}
Node *appendLastNToFirst(Node *head, int n){
	if(head==NULL || n==0){
		return head;
	}
	int pos=0,l=le(head);
	if(n>=l){
		return head;
	}
    l =l- n-1;
	Node*temp=head;
	while(true){
		if(pos==l){
			Node*n=head;
			head=head->next;
			n->next=NULL;	
			break;
		}
		head=head->next;
		pos++;
	}

	Node* t=head;
    while (true) {
		if(t->next==NULL){
			t->next=temp;
			break;
		}
    	t = t->next;
    }
	return head;
}