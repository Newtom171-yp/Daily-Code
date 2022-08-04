class Solution{
public:    
    bool isCompleteBT(Node* root){
        //code here
        queue<Node*> q;
        bool flag = false;
        
        if(!root) return true;
        
        q.push(root);
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(!temp) flag = true;
            else if(flag) return false;
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};