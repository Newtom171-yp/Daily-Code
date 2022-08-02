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

int main()
{

    node* root = NULL;

    root = buildTree(root);

    cout << " The Level Order Traversal of the Tree is :"<< endl;

    levelOrderTraversal(root);

    cout << "The Reverse Level Order Traversal of the Tree is :" << endl;
    reverseLevelOrder(root);

    return 0;
}