class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        Node* pre;
        while(curr)
        {
            if(curr->left)
            {
                pre = curr->left;
                while(pre->right) pre = pre->right;
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};