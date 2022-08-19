/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorderTraversal(TreeNode<int>* root, vector<int> &inorder)
{
    if(!root) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
TreeNode<int>* buildTree(int start, int end, vector<int> &inorder)
{
    if(start > end) return NULL;
    int mid = start + (end - start)/2;
    TreeNode<int>* root = new TreeNode<int>(inorder[mid]);
    root->right = buildTree(mid + 1, end, inorder);
    root->left = buildTree(start, mid - 1, inorder);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> inorder;
    inorderTraversal(root, inorder);
    return buildTree(0, inorder.size()-1, inorder);
}
