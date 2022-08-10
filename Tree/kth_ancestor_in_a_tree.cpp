int approach1(Node* root, int k, int node, vector<int> &ancestors)
{
    if(!root) return -1;
    
    if(root->data == node)
    {
        if(ancestors.size() < k) return -1;
        
        return ancestors[ancestors.size()-k];
    }
    
    ancestors.push_back(root->data);
    
    int ans1 = approach1(root->left,k,node,ancestors);
    int ans2 = approach1(root->right,k,node,ancestors);
    
    ancestors.pop_back();
    return max(ans1,ans2);
}

Node* solve(Node* &root, int &k, int node)
{
    if(!root) return NULL;
    
    if(root->data == node) return root;
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if(!leftAns && rightAns)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    
    if(leftAns && !rightAns)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    
    // vector<int> ancestors;
    
    // return approach1(root,k,node,ancestors);
    
    if(!root || root->data == node) return -1;
    
    Node* ans = solve(root,k,node);
    
    if(!ans || ans->data == node) return -1;
}