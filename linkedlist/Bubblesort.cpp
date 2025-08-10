Node *bubbleSort(Node *head){
	if(head==NULL || head->next==NULL){
        return head;
    }
    Node *tail=NULL;
    while(tail!=head->next){
         Node *phead=NULL,*mhead=head,*fhead=head->next;
        while(fhead!=tail){
            if(mhead->data>fhead->data){
              mhead->next = fhead->next;
              fhead->next = mhead;
              if (phead == NULL) {
                    head = fhead;
                }else{
                    phead->next=fhead;
                }
                phead=fhead;
                fhead=mhead->next;
            }else{
                phead=mhead;
                mhead=fhead;
                fhead=fhead->next;
            }
        }
        mhead->next=tail;
        tail=mhead;
        }   
    return head;
}