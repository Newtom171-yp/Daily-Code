int solve(Node *root, int k, int &i)
{
    if(!root) return -1;
    
    int left = solve(root->left, k, i);
    
    if(left != -1) return left;
    
    i++;
    if(i == k) return root->data;
    
    return solve(root->right, k, i);
    
}

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        int i = 0;
        return solve(root, K, i);
    }
};