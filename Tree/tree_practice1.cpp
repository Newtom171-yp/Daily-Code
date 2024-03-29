#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(node* root)
{
    cout << "Enter the data: " << endl;
    int data,left,right;
    cin >> data;
    root = new node(data);

    if(data == -1) return NULL;

    cout << "Enter data for left" << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for right" << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* &root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        if(temp) cout << temp->data << " ";
        q.pop();

        if(!temp) 
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        }
    }
}

void reverseLevelOrder(node * &root)
{
    // code here
    stack<node*> s;
    queue<node*> q;

    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        s.push(temp);
        q.pop();
        if(!temp) 
        {
            if(!q.empty()) q.push(NULL);
        }
        else
        {
            if(temp->right)
            q.push(temp->right);
            
            if(temp->left)
            q.push(temp->left);
        }
    }
    while(!s.empty())
    {
        if(s.top() == NULL)
        cout << endl;
        else cout << s.top()->data << " ";
        s.pop();
    }
}

void inOrder(node* &root)
{
    if(!root) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node* &root)
{
    if(!root) return;

    cout << root->data << " ";
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(node* &root)
{
    if(!root) return;

    inOrder(root->left);
    inOrder(root->right);
    cout << root->data << " ";
}

void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: "<< temp->data << endl;
        
        int leftData;
        cin >> leftData;

        if(leftData != -1)
        {
            temp ->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: "<< temp->data << endl;
        
        int rightData;
        cin >> rightData;

        if(rightData != -1)
        {
            temp ->right = new node(rightData);
            q.push(temp->right);
        }

    }
}

int main()
{

    node* root = NULL;

    buildFromLevelOrder(root);

    // root = buildTree(root);

    cout << endl << "The Level Order Traversal of the Tree is :"<< endl;

    levelOrderTraversal(root);

    // cout << endl << "The Reverse Level Order Traversal of the Tree is :" << endl;
    // reverseLevelOrder(root);

    // cout<< endl << "The Inorder traversal of the tree is: "<< endl;
    
    // inOrder(root);
    
    // cout<< endl << "The preorder traversal of the tree is: "<< endl;
    
    // preOrder(root);

    // cout<< endl << "The postorder traversal of the tree is: "<< endl;

    // postOrder(root);

    return 0;
}