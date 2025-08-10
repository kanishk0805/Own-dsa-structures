class retbst{
	public:
	bool res;
	int minimum;
	int maximum;
};
retbst helper(BinaryTreeNode<int> *root){
	retbst output;
	if(root==NULL){
		output.res=true;
		output.minimum=2147483647;
		output.maximum=-2147483648;
		return output;
	}
	retbst lw=helper(root->left);
	retbst rw=helper(root->right);
	output.maximum=max(root->data,max(lw.maximum,rw.maximum));
	output.minimum=max(root->data,min(lw.minimum,rw.minimum));
	output.res=(root->data<=rw.minimum) &&(root->data>lw.maximum) && lw.res && rw.res;
	return output;
}
bool isBST(BinaryTreeNode<int> *root) {
	return helper(root).res;
}