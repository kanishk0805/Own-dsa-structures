#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;
void printlevelwise(TreeNode<int>* tree){
    queue<TreeNode<int>*> q;
    q.push(tree);
    while(!q.empty()){
        TreeNode<int> *front=q.front();
        cout<<front->data<<":";
        q.pop();
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<',';
            q.push(front->children[i]);
        }
        cout<<endl;
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
TreeNode<int>* takeinputLevelwise(){
    int treedata;
    cout<<"ENETER the main tree data:";
    cin>>treedata;
    TreeNode<int> *tree=new TreeNode<int>(treedata);
    queue<TreeNode<int>*> q;
    q.push(tree);
    while(!q.empty()){
        TreeNode<int> *front=q.front();
        int num;
        q.pop();
        cout<<"ENTER number of children of "<<front->data<<endl;
        cin>>num;
        for(int i=0;i<num;i++){
            int data;
            cout<<"enter the data of "<<i+1<<"th child"<<endl;
            cin>>data;
            TreeNode<int> *childtree=new TreeNode<int>(data);
            front->children.push_back(childtree);
            q.push(childtree);
        }
    }
    return tree; 
}
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
int main(){
    TreeNode<int> *NODE=takeinputLevelwise();
    printlevelwise(NODE);
    //printtree(NODE);
    deletetnode(NODE);
}