class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    pair<bool,int> BalNHeight(Node*&root)
    {
        if(!root)
        {
            pair<bool,int> ans = make_pair(true,0);
            return ans;
        }
        
        pair<bool,int> leftTree = BalNHeight(root->left);
        pair<bool,int> rightTree = BalNHeight(root->right);
        
        bool leftBal = leftTree.first;
        bool rightBal = rightTree.first;
        
        bool diff = (abs(leftTree.second-rightTree.second) <= 1);
        
        int height = 1 + max(leftTree.second,rightTree.second);
        
        pair<bool,int> ans;
        ans.first = (leftBal && rightBal && diff);
        ans.second = height;
        
        return ans;
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return BalNHeight(root).first;
    }
};