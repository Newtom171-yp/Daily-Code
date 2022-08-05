class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root, vector<int> &ans, int level)
{
    if(!root) return;
    
    if(level == ans.size()) ans.push_back(root->data);
    
    solve(root->right, ans, level+1);
    solve(root->left,ans,level+1);
}

vector<int> rightView(Node *root)
{
   // Your code here
   vector<int> ans;
   
   solve(root, ans, 0);
   
   return ans;
}
};