#include <iostream>
#include "TreeNode.h"
using namespace std;
void printtree(TreeNode<int>* node){
    cout<<node->data<<":";
    for(int i=0;i<node->children.size();i++){
        cout<<node->children.at(i)->data<<',';
    }
    cout<<endl;
    for(int i=0;i<node->children.size();i++){
        printtree(node->children.at(i));
    }
    return; 
}
void deletetnode(TreeNode<int>* node){
    if(node->children.size()==0){
        delete node;
        return;
    }
    for(int i=0;i<node->children.size();i++){
        deletetnode(node->children.at(i));
    }
}
void takeinput(TreeNode<int>* tree){
    int num;
    cout<<"ENTER number of children of:"<<tree->data<<endl;
    cin>>num;
    cout<<"ENTER children of:"<<tree->data<<endl;
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        TreeNode<int> *node=new TreeNode<int>(data);
        tree->children.push_back(node);
    }
    for(int i=0;i<num;i++){
        takeinput(tree->children[i]);
        cout<<endl;
    }
}
int main(){
    int data;
    cout<<"ENTER MAIN Data :"<<endl;
    cin>>data;
    TreeNode<int> *node=new TreeNode<int>(data);
    takeinput(node);
    printtree(node);
    deletetnode(node);
}