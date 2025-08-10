#include <iostream>
using namespace std;
#include "node.cpp"
node* input(){
    node*head=NULL;
    int data;
    cin>>data;
    if(data==-1){
        return head;
    }else{
        node *n1=new node(data);
        head=n1;
    }
    node*temp=head;
    while(true){
        cin>>data;
        if(data==-1){
            return head;
        }
        node *nn=new node(data);
        temp->next=nn;
        temp=nn; 
    }
}
void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
node* insertn(node *head,int i,int data){
    node *n= new node(data);
    int p=0;
    node*temp=head;
    if(i==0){
        n->next=head;
        temp=n;
        return temp;
    }
    while(head->next!=NULL){
        if(i-1==p){
            n->next=head->next;
            head->next=n;
            break;
        }
        head=head->next;
        p++;
    }
        head->next=n;
        return temp;
}
node* deleten(node *head,int i){
    int p=0;
    node* temp=head;
    if(i==0){
        node *n=head;
        head=head->next;
        delete n;
        return head;
    }
    i--;
    while(p<i && head->next!=NULL){
        head=head->next;
        p++;
    }
    node *n=head->next;
    head->next=n->next;
    delete n;
    return temp;
}
int main(){
    /*node n1(1);
    node* head=&n1;
    node n2(3);
    n1.next=&n2;
    node n3(4);
    n2.next=&n3;
    print(head);
    */
   node *head=input();
   head=insertn(head,2,3);
   print(head);
   head =deleten(head,2);
    print(head);
}