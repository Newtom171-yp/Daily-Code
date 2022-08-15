class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    Node* LCA(struct Node* &root, int n1, int n2)
    {
        if(!root) return NULL;
        if(root->data == n1 || root->data == n2) return root;
       
       Node* leftAns = LCA(root->left, n1, n2);
       Node* rightAns = LCA(root->right, n1, n2);
       
       if(leftAns && rightAns) return root;
       
       else if(!leftAns && rightAns) return rightAns;
       
       else if(leftAns && !rightAns) return leftAns;
       
       else return NULL;
    }
    
    bool turns(Node* &root, int data, bool turn, int &count)
    {
        if(!root) return false;
        
        if(root->data == data) return true;
        
        if(turn)
        {
            if(turns(root->left, data, turn, count)) return true;
            if(turns(root->right, data, !turn, count))
            {
                count++;
                return true;
            }
        }
        else
        {
            if(turns(root->right, data, turn, count)) return true;
            if(turns(root->left, data, !turn, count))
            {
                count++;
                return true;
            }
        }
        return false;
    }
    
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      struct Node* commonAncestor = LCA(root, first, second);
      if(!commonAncestor) return -1;
      int count = 0;
      
      //case1
      if(commonAncestor->data != first && commonAncestor->data != second)
      {
          if(turns(commonAncestor->right, second, false, count) || turns(commonAncestor->left, second, true, count));
          
          if(turns(commonAncestor->left, first, true, count) || turns(commonAncestor->right, first, false, count));
          
          return count+1;
      }
      
      if(commonAncestor->data == first)
      {
          turns(commonAncestor->right, second, false, count);
          turns(commonAncestor->left, second, true, count);
          return count;
      }
      else
      {
          turns(commonAncestor->right, first, false, count);
          turns(commonAncestor->left, first, true, count);
          return count;
      }
    }
};