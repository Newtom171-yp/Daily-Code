class info
{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(TreeNode<int>* root, int & ans)
{
    if(!root) return {INT_MIN, INT_MAX, true, 0};
    
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    
    info curr;
    curr.size = left.size + right.size + 1;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);
    
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) curr.isBST = true;
    else curr.isBST = false;
    
    if(curr.isBST) ans = max(ans,curr.size);
    
    return curr;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}