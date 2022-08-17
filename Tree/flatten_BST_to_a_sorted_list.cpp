/************************************************************

    Following is the Binary Tree node structure
    
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
void inorderTraversal(TreeNode<int>* root, vector<int> & inorder)
{
    if(!root) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> inorder;
    inorderTraversal(root, inorder);
    TreeNode<int>* curr = new TreeNode<int>(inorder[0]);
    TreeNode<int>* firstNode = curr;
    for(int i = 1; i < inorder.size(); i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(inorder[i]);
        curr->right = temp;
        curr->left = NULL;
        curr = curr->right;
    }
    curr->right = NULL;
    curr->left = NULL;
    return firstNode;
}
