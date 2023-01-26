class Solution {
  public:
  
    bool isCBT(Node* root, int i, int nodeCount){
        if(!root) return true;
        
        if(i >= nodeCount) return false;
        
        bool left = isCBT(root->left, 2*i + 1, nodeCount);
        bool right = isCBT(root->right, 2*i + 2, nodeCount);
        
        return (left && right);
    }
    
    bool isMaxOrder(Node* root){
        if(!root->left && !root->right) return true;
        
        if(root->left && !root->right) return (root->data > root->left->data);
        
        return(root->data > root->left->data && root->data > root->right->data && isMaxOrder(root->left) && isMaxOrder(root->right));
    }
    
    int countNode( struct Node* root)
    {
        if(!root) return 0;
        return (1 + countNode(root->right) + countNode(root->left));
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int nodeCount = countNode(tree);
        return (isCBT(tree, index, nodeCount) && isMaxOrder(tree));
    }
};