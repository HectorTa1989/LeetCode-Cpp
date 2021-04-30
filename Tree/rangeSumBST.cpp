int rangeSumBST(treeNode *root, int l, int r)
{
	if(!root ) return 0;
	return ((root->data > l && root->data < r) ? root->data : 0) + rangeSumBST(root->left, l, r) + rangeSumBST(root->right, l, r);
}