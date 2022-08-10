class Solution{
    public:
    
    Node* solve(int in[], int pre[], int &preIndex, int first, int last, int size)
    {
        if(first > last || last < first || preIndex >= size) return NULL;
        
        Node* root = new Node(pre[preIndex++]);
        
        int rootIndex = 0;
        
        for(int i = first; i <= last; i++)
        {
            if(root->data == in[i]) 
            {
                rootIndex = i;
                break;
            }
        }
        
        root->left = solve(in, pre, preIndex, first, rootIndex - 1, size);
        root->right = solve(in, pre, preIndex, rootIndex + 1, last, size);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preIndex = 0;
        return solve(in, pre, preIndex, 0, n-1, n);
    }
};