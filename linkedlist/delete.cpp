Node *deleteNode(Node *head, int i){
   if(head==NULL || i>len){
        return head;
    }
    if (i == 0) {
      Node *n = head->next;
      delete head;
      return n;
    }
    int p=0;
    Node* temp=head;
    while(p<len){
		if(p==i-1){
			break;
		}
        cout<<'h'<<endl<<len<<endl;
        head=head->next;
        p++;
    }
    Node *n=head->next;
    head->next=head->next->next;
    delete n;
    return temp;
}
