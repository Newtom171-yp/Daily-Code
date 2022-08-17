// Following is the Binary Tree node structure
/**************
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
    
};
***************/
void inorderTraversal(BinaryTreeNode<int>* root, vector<int> &inorder)
{
    if(!root) return;
    
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> inorder;
    inorderTraversal(root, inorder);
    int start = 0, end = inorder.size() - 1;
    while(start < end)
    {
        if(inorder[start] + inorder[end] == target) return true;
        else if(inorder[start] + inorder[end] < target) start++;
        else end--;
    }
    return false;
}