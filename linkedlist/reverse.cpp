void print(Node *head){
  while(head!=NULL){
    cout<<head->data;
    head=head->next;
  }
}

void printReverse(Node *head){
  if(head==NULL){
    return;
  }else if (head->next==NULL){
    cout<<head->data;
    return;
  }
  
  Node *mid=head->next;
  Node *tail = mid->next;
  head->next=NULL;
  while (tail!=NULL) {
  mid->next=head;
  head=mid;
  mid=tail;
  tail=tail->next;
}
  mid->next=head;
  print(mid);
}
/* time better
void print(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  
}
void printReverse(Node *head) {
  if(head==NULL){
    return;
  }else if(head->next==NULL){
      print(head);
      return;
  }
  Node *mid = new Node(head->data);
  mid->next = NULL;
  while (head->next != NULL) {
    head = head->next;
    Node *t = new Node(head->data);
    t->next = mid;
    mid = t;
  }
  print(mid);
  return;
}*/