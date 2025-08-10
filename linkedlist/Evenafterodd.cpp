/*Node *evenAfterOdd(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	int e=0,o=0;
	Node * ho=NULL,*temp=head,*ph=NULL;
	while(temp->next!=NULL){
		if(temp->data%2==0){
			e=1;
		}else{
			o++;
			if(o==1){
				if(ph!=NULL){
					ph->next=temp->next;
					ho=temp;
					ho->next=head;
					temp=ph->next;
					head=ho;
				}
				ho=head;
				continue;
			}
		}
		ph=temp;
		temp=temp->next;
		
	}
	if(o==0 || e==0 ){
		return head;
	}
	temp=head->next;
	ph=head;
	while(temp!=NULL){
		if(temp->data%2!=0){
			ph->next=temp->next;
			temp->next=ho->next;
			ho->next=temp;
			if(ph==ho){
				ph=ph->next;
			}
			temp=ph->next;			
			ho=ho->next;
		}else{
			ph=temp;
			temp=temp->next;
		}
	}
	return head;
}*/
Node *evenAfterOdd(Node *head){
	
}