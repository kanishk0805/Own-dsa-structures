#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeinput(){
    int treedata,num;
    cout<<"ENETER the tree data:";
    cin>>treedata;
    TreeNode<int> *node=new TreeNode<int>(treedata);
    cout<<"ENTER number of children"<<endl;
    cin>>num;
    for(int i=0;i<num;i++){
        TreeNode<int> *childtree=takeinput();
        node->children.push_back(childtree);
    }
    return node; 
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
    TreeNode<int> *NODE=takeinput();
    printtree(NODE);
	
}