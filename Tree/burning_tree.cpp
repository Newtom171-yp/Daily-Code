class Solution {
  public:
  
    Node* parentMap(Node* &root, int target, map<Node*, Node*> &m)
    {
        Node* res = NULL;
        
        queue<Node*> q;
        m[root] = NULL;
        q.push(root);
        
        while(!q.empty())
        {
            Node* frontNode = q.front();
            q.pop();
            
            
            if(frontNode->data == target)
            {
                res = frontNode;
            }
            
            if(frontNode->left)
            {
                m[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }
            
            if(frontNode->right)
            {
                m[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
        }
        
        return res;
    }
    
    int burn(Node* root, map<Node*, Node*> &m, int ans)
    {
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root] = true;
        
        while(!q.empty())
        {
            
            bool flag = false;
            
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                //processing neighbouring nodes
                
                Node* frontNode = q.front();
                q.pop();
                
                if(frontNode->left && !visited[frontNode->left])
                {
                    flag = true;
                    q.push(frontNode->left);
                    visited[frontNode->left] = true;
                }
                
                if(frontNode->right && !visited[frontNode->right])
                {
                    flag = true;
                    q.push(frontNode->right);
                    visited[frontNode->right] = true;
                }
                
                if(m[frontNode] && !visited[m[frontNode]])
                {
                    flag = true;
                    q.push(m[frontNode]);
                    visited[m[frontNode]] = true;
                }
            }
            if(flag)
            {
                ans++;
            }
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int ans = 0;
        map<Node*, Node*> nodeToParent;
        
        Node* targetNode = parentMap(root, target, nodeToParent);
        
        return burn(targetNode, nodeToParent, ans);
    }
};