class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    
    pair<int,int> solve(Node* &root)
    {
        if(!root)
        {
            pair<int,int> ans= make_pair(0,0);
            return ans;
        }
        
        pair<int,int> leftTree = solve(root->left);
        pair<int,int> rightTree = solve(root->right);
        
        pair<int,int> result;
        result.first = root->data + leftTree.second + rightTree.second;
        result.second = max(leftTree.first, leftTree.second) + max(rightTree.first, rightTree.second);
        
        return result;
    }
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans = solve(root);
        
        return max(ans.first,ans.second);
    }
};