class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(struct Node* node){
        // code here 
        if(!node) return 0;
        
        return 1 + max(height(node->left),height(node->right));
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root) return true;
        
        bool leftTree = isBalanced(root->left);
        bool rightTree = isBalanced(root->right);
        bool diff = (abs(height(root->left) - height(root->right)) <= 1);
        
        return (leftTree && rightTree && diff);
    }
};