class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> diaNheight(Node* &root)
    {
        if(!root)
        {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> leftTree = diaNheight(root->left);
        pair<int,int> rightTree = diaNheight(root->right);
        
        int Llength = leftTree.first;
        int Rlength = rightTree.first;
        int Mid = 1 + leftTree.second + rightTree.second;
        
        pair<int,int> ans;
        
        ans.first = max({Llength,Rlength,Mid});
        ans.second = 1 + max(leftTree.second, rightTree.second);
        
        return ans;
    }
    
    int diameter(Node* root) {
        // Your code here
        return diaNheight(root).first;
    }
};