bool solve(Node* & left, Node* & right)
{
    if(!left && !right) return true;
    if(left && !right) return false;
    if(!left && right) return false;
    
    return (solve(left->left, right->right) && solve(left->right, right->left));
}

bool IsFoldable(Node* root)
{
    // Your code goes here
    if(!root) return true;
    
    return solve(root->left, root->right);
}