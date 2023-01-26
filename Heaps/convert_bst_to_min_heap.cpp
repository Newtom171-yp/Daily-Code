#include <bits/stdc++.h> 
using namespace std;
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/

void inorder(BinaryTreeNode* &root, vector<int> & v)
{
	if(!root) return;

	inorder(root->left, v);
	v.push_back(root->data);
	inorder(root->right, v);
}

void preorder(BinaryTreeNode* &root, vector<int> & v, int &i)
{
	if(!root) return;

	root->data = v[i++];

	preorder(root->left, v, i);
	preorder(root->right, v, i);

}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int> v;
	inorder(root,v);
	int i = 0;
	preorder(root,v,i);

	return root;
}