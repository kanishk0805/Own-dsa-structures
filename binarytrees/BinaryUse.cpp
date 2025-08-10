#include <iostream>
using namespace std;
#include "mainbinarytree.cpp"
#include <queue>
BinaryTree<int> * takeinput(){
    int data;
    cout<<"enter the main data :"<<endl;
    cin>>data;
    BinaryTree<int> *root=new BinaryTree<int>(data);
    queue <BinaryTree<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTree<int> * front=q.front();
        q.pop();
        int ldata;
        cout<<"enter the left data of "<<front->data<<endl;
        cin>>ldata;
        if(ldata!=-1){
           BinaryTree<int> * tleft= new BinaryTree<int>(ldata);
           front->Left=tleft;
           q.push(tleft); 
        }
        int rdata;
        cout<<"enter the right data of "<<front->data<<endl;
        cin>>rdata;
        if(rdata!=-1){
           BinaryTree<int> * tright= new BinaryTree<int>(rdata);
           front->Right=tright;
           q.push(tright); 
        }
    }
    return root;
}
void printTreelevel(BinaryTree<int> *root){
    if(root==NULL){
        return;
    }
    queue <BinaryTree<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTree<int> * front=q.front();
        q.pop();
        cout<<front->data<<':';
        if(front->Left!=NULL){
           cout<<'L'<<front->Left->data<<',';
           q.push(front->Left); 
        }else{
            cout<<"L:-1,";
        }
        if(front->Right!=NULL){
           cout<<'R'<<front->Right->data;
           q.push(front->Right); 
        }else{
            cout<<"R:-1";
        }
        cout<<endl;
    }
    return;
}
int countnodes(BinaryTree<int> *root){
    if(root==NULL){
        return 0;
    }
    return 1+countnodes(root->Left)+countnodes(root->Right);
}
/* 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 */
void printLevelWise(BinaryTree<int> *root) {
    if(root==NULL){
        return ;
    }
    queue<BinaryTree<int> *> q;
    q.push(root);
    int esize=1;
    while(!q.empty()){
        BinaryTree<int> * front=q.front();
        q.pop();
        cout<<front->data<<" ";
        if(front->Left!=NULL){
            q.push(front->Left);
        }
        if(front->Right!=NULL){
            q.push(front->Right);
        }
        esize--;
        if(esize==0){
            esize=q.size();
            cout<<endl;
        }
    }
    return;
}
int main(){
    BinaryTree<int> * tree=takeinput();
    printTreelevel(tree);
    //printLevelWise(tree);
    delete tree;
}