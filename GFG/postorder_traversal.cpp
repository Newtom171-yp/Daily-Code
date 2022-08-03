void solve(vector<int>& ans, Node* &root)
    {
        if(!root) return;
        
        solve(ans,root->left);
        
        solve(ans,root->right);
        
        ans.push_back(root->data);
    }


vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  solve(ans,root);
  return ans;
}