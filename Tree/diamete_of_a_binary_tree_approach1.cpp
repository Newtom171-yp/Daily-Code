class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    int height(struct Node* node){
        // code here 
        if(!node) return 0;
        
        return 1 + max(height(node->left),height(node->right));
    }
    
    int diameter(Node* root) {
        // Your code here
        if(!root) return 0;
        
        int Llength = diameter(root->left);
        
        int Rlength = diameter(root->right);
        
        int Mid = 1 + height(root->left) + height(root->right);
        
        return max({Llength, Rlength, Mid});
    }
};