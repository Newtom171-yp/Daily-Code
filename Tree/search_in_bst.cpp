bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(!root) return false;
    
    BinaryTreeNode<int>* curr = root;
    while(curr)
    {
        if(curr->data == x) return true;
        if(curr->data < x) curr = curr->right;
        else curr = curr->left;
    }
    return false;
}