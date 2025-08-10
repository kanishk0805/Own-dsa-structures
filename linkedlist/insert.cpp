Node* insertNode(Node *head, int i, int data) {
	if(i==0){
		Node *n=new Node(data);
		n->next=head;
		head=n;
		return head;
	}
	if(head->next==NULL){
		return head;
	}
    cout<<i--<<endl;
	head->next=insertNode(head->next,i,data);
	return head;
}