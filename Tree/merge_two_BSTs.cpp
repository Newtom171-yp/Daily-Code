/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorderTraversal(TreeNode<int> *&root, vector<int> & inorder)
{
    if(!root) return;
    
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}
vector<int> mergeSorted(vector<int>& one, vector<int> & two)
{
    vector<int> ans;
    int first = 0, second = 0;
    while(first < one.size() && second < two.size())
    {
        if(one[first] <= two[second])
        {
            ans.push_back(one[first]);
            first++;
        }
        else
        {
            ans.push_back(two[second]);
            second++;
        }
    }
    while(first < one.size())
    {
        ans.push_back(one[first++]);
    }
    while(second < two.size())
    {
        ans.push_back(two[second++]);
    }
    return ans;
}
TreeNode<int>* inorderToBST(vector<int> &inorder, int start, int end)
{
    if(start > end) return NULL;
    int mid = start + (end - start)/2;
    TreeNode<int>* root = new TreeNode<int>(inorder[mid]);
    root->right = inorderToBST(inorder, mid + 1, end);
    root->left = inorderToBST(inorder, start, mid - 1);
    return root;
}
TreeNode<int> *solve1(TreeNode<int> *&root1, TreeNode<int> *&root2)
{
    vector<int> inorder1;
    vector<int> inorder2;
    inorderTraversal(root1, inorder1);
    inorderTraversal(root2, inorder2);
    vector<int> sorted = mergeSorted(inorder1, inorder2);
    return inorderToBST(sorted, 0, sorted.size() - 1);
}
void bstToDLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    if(!root) return;
    
    bstToDLL(root->right, head);
    root->right = head;
    if(head)
        head->left = root;
    
    head = root;
    bstToDLL(root->left, head);
}

TreeNode<int> * mergeLL(TreeNode<int> *& head1, TreeNode<int> *& head2)
{
    TreeNode<int> * head = NULL;
    TreeNode<int> * tail = NULL;
    
    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            if(!head)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(!head)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    
    while(head1)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}
int countNode(TreeNode<int>* head)
{
    int count = 0;
    TreeNode<int>* temp = head;
    while(temp)
    {
        temp = temp->right;
        count++;
    }
    return count;
}
TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n)
{
    if(n <= 0 || !head) return NULL;
    
    TreeNode<int>* left = sortedLLToBST(head, n/2);
    
    TreeNode<int>* root = head;
    
    root->left = left;
    
    head = head->right;
    
    root->right = sortedLLToBST(head, n - n/2 - 1);
    
    return root;
}

TreeNode<int> *solve2(TreeNode<int> *&root1, TreeNode<int> *&root2)
{
    TreeNode<int>* head1 = NULL;
    bstToDLL(root1, head1);
    head1->left = NULL;
    
    TreeNode<int>* head2 = NULL;
    bstToDLL(root2, head2);
    head2->left = NULL;
    
    TreeNode<int>* head = mergeLL(head1, head2);
    
    return sortedLLToBST(head, countNode(head));
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
//     return solve1(root1, root2);
    return solve2(root1, root2);
}