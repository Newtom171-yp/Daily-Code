/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
TreeNode<int>* solve1(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(root->data < P->data && root->data < Q->data)
        return solve1(root->right, P, Q);
    else if(root->data > P->data && root->data > Q->data)
        return solve1(root->left, P, Q);
    return root;
}
TreeNode<int>* solve2(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(!root) return NULL;
    while(root)
    {
        if(root->data < P->data && root->data < Q->data) root = root->right;
        else if(root->data > P->data && root->data > Q->data) root = root->left;
        else return root;
    }
    return root;
}
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    //return solve1(root, P, Q);
    return solve2(root, P, Q);
}
