// Function to delete a node from BST.
Node* maxVal(Node* & root)
{
    if(!root) return root;
    
    Node* temp = root;
    
    while(temp->right) temp = temp->right;
    
    return temp;
}
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(!root) return NULL;
    
    if(root->data == X)
    {
        //leaf node
        
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        
        //one child
        
            //when only left is NULL
        if(root->right && !root->left)
        {
            Node* temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }
            //when only right is NULL
        if(!root->right && root->left)
        {
            Node* temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }
        
        //two children
        if(root->left && root->right)
        {
            int maxi = maxVal(root->left)->data;
            root->data = maxi;
            root->left = deleteNode(root->left, maxi);
            return root;
        }
        
    }
    
    else if (root->data > X)
    {
        root->left = deleteNode(root->left, X);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, X);
        return root;
    }
    
}