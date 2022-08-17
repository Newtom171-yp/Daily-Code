class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool solve(int &lower, int &upper, Node*& root)
    {
        if(!root) return true;
        if(!(root->data < upper && root->data > lower)) return false;
        
        return (solve(lower, root->data, root->left) && solve(root->data, upper, root->right));
    }
    
    bool isBST(Node* root) 
    {
        // Your code here
        int lower = INT_MIN;
        int upper = INT_MAX;
        
        return solve(lower, upper, root);
    }
};