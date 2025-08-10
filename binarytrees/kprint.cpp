#include <iostream>
#include <queue>
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};
using namespace std;
BinaryTreeNode<int> * pheadofnode(BinaryTreeNode<int> *node,BinaryTreeNode<int> *head){
        if(node==NULL && head==NULL){
                return NULL;
        }
        BinaryTreeNode<int> *temp=head;
        if(temp->left==node || temp->right==node){
                cout<<"node data is"<<node->data<<"head data is"<<head->data<<endl;
                return head;
        }
        BinaryTreeNode<int> *resl=pheadofnode(node, temp->left);
        BinaryTreeNode<int> *resr=pheadofnode(node, temp->right);
        if (resl == NULL) {
                 return resr ;
        }
       return resl;
}
void pdown(BinaryTreeNode<int> *root,int k){
        if(root==NULL || k<0){
                return;
        }
        if(k==0){
                cout<<root->data<<endl;
                return;
        }
        pdown(root->left,k-1);
        pdown(root->right,k-1);
}
void pup(BinaryTreeNode<int> *root,int k,BinaryTreeNode<int> * head){
        if(root==NULL || k<0){
                return;
        }
        if(k==0){
                cout<<root->data<<endl;
                return;
        }
        if(head!=root){
                BinaryTreeNode<int> *ins =pheadofnode(root, head);
                pup(ins,k-1,head);
                if(ins ->right!=NULL && ins->right==root){
                        pdown(ins->left,k-2);
                }else{
                        pdown(ins->right,k-2);
                }
        }
}
void helper(BinaryTreeNode<int> *root, int node, int k,BinaryTreeNode<int> * head){
         if(root==NULL || k<0){
            return;
        }
        if(root->data==node){
                pdown(root->right,k-1);
                pdown(root->left,k-1);
                pup(root,k,head);
                
        }
        helper(root->left,node, k,head);
        helper(root->right,node, k,head); 
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
        helper(root,  node,  k, root);
}
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}