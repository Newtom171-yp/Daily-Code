class Solution
{
    public:
    
    pair<bool,int> isSum(Node* root)
    {
        if(!root)
        {
            pair<bool,int> ans = make_pair(true,0);
            
            return ans;
        }
        
        if(!root->left && !root->right)
        {
            pair<bool,int> ans = make_pair(true,root->data);
            return ans;
        }
        
        pair<bool,int> leftTree = isSum(root->left);
        pair<bool,int> rightTree = isSum(root->right);
        
        pair<bool,int> ans;
        
        ans.first = (root->data == leftTree.second + rightTree.second) && leftTree.first && rightTree.first;
        ans.second = root->data + leftTree.second + rightTree.second;
        
        return ans;
        
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSum(root).first;
    }
};