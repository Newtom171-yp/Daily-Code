void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    //base case
    if(!root) return;
    
    
    //if root is the key
    if(root->key == key)
    {
        //max value in the left subtree is the predecessor
        if(root->left)
        {
            Node* temp = root->left;
            while(temp->right) temp = temp->right;
            pre = temp;
        }
        
        //min value in the right subtree is the successor
        
        if(root->right)
        {
            Node* temp = root->right;
            while(temp->left) temp = temp->left;
            suc = temp;
        }
        
        return;
    }
    
    if(key < root->key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}