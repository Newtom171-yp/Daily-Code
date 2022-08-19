/*
    Following is the class structure of BinaryTreeNode class for referance:

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
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int>* solve(vector<int> &preorder, int lower, int upper, int &index)
{
    if(!(preorder[index] < upper && preorder[index] > lower)) return NULL;
    if(index == preorder.size()) return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[index++]);
    root->left = solve(preorder, lower, root->data, index);
    root->right = solve(preorder, root->data, upper, index);
    
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = 0;
    return solve(preorder, mini, maxi, index);
}