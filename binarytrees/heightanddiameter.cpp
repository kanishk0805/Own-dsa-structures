#include <iostream>
using namespace std;
#include "mainbinarytree.cpp"
#include<queue>
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
pair<int,int> hd(BinaryTree<int>* root){
    pair<int,int> p;
    if(root==NULL){
        p.first=0,p.second=0;
        return p;
    }
    pair <int,int> resl=hd(root->Left);
    pair <int,int> resr=hd(root->Right);
    p.first=1+max(resl.first,resr.first);
    p.second=max(resl.first+resr.first,max(resr.second,resl.second));
    return p;
} 
int main(){
    BinaryTree<int> * tree=takeinput();
    pair<int,int> p=hd(tree);
    cout<<p.first<<"   "<<p.second; 
    delete tree;
}