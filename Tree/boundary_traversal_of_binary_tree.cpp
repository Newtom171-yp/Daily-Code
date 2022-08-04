class Solution {
public:

    void traverseLeft(Node* &root, vector<int>&result)
    {
        if(!root) return;
        
        if(!root->left && !root->right) return;
        
        result.push_back(root->data);
        
        if(root->left) traverseLeft(root->left,result);
        else traverseLeft(root->right, result);
    }
    
    void traverseLeaf(Node*&root, vector<int> & result)
    {
        if(!root) return;
        
        if(!root->left && !root->right) result.push_back(root->data);
        
        traverseLeaf(root->left, result);
        traverseLeaf(root->right, result);
    }
    
    void traverseRight(Node*&root, vector<int> &result)
    {
        if(!root) return;
        
        if(!root->left && !root->right) return;
        
        
        if(root->right) traverseRight(root->right,result);
        else traverseRight(root->left, result);
        
        result.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> result;
        if(!root) return result;
        
        result.push_back(root->data);
        
        traverseLeft(root->left, result);
        
        traverseLeaf(root->left,result);
        
        traverseLeaf(root->right, result);
        
        traverseRight(root->right,result);
        return result;
    }
};