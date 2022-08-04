class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	bool LToR = true;
    	vector<int> result;
    	
    	if(!root) return result;
    	
    	queue<Node*> q;
    	
    	q.push(root);
    	
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    vector<int> v(size);
    	    
    	    for(int i  = 0; i < size; i++)
    	    {
    	        Node* temp = q.front();
    	        q.pop();
    	        
    	        int index = (LToR) ? i : size - 1 - i;
    	        
    	        v[index] = temp->data;
    	        
    	        if(temp->left) q.push(temp->left);
    	        if(temp->right) q.push(temp->right);
    	    }
    	    LToR = !LToR;
    	    for(auto &x : v)
    	    {
    	        result.push_back(x);
    	    }
    	}
    	return result;
    }
};