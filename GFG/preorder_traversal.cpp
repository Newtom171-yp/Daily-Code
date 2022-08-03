void solve(vector<int>& ans, Node* &root)
    {
        if(!root) return;
        
        ans.push_back(root->data);
        
        solve(ans,root->left);
        
        solve(ans,root->right);
    }

vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> ans;
  solve(ans,root);
  return ans;
}