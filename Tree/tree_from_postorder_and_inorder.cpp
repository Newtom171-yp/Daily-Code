Node* solve(int in[], int post[], int &postIndex, int first, int last, unordered_map<int,int> &m)
{
    if(first > last) return NULL;
    
    Node* root = new Node(post[postIndex--]);
    
    root->right = solve(in, post, postIndex, m[root->data] + 1, last, m);
    root->left = solve(in, post, postIndex, first, m[root->data] - 1, m);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIndex = n - 1;
    unordered_map <int,int> m;
    for(int i = 0; i < n; i++)
    {
        m[in[i]] = i;
    }
    return solve(in, post, postIndex, 0, n - 1, m);
}