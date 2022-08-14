#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void inOrder(Node* &root)
{
    if(!root) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* &root)
{
    if(!root) return;

    cout << root->data << " ";
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(Node* &root)
{
    if(!root) return;

    inOrder(root->left);
    inOrder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* &root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
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

Node* insertIntoBST(Node*&root, int data)
{
    Node* newNode = new Node(data);

    if(!root) return newNode;

    if(newNode->data > root->data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);
    
    return root;
}

void takeInput(Node* & root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main()
{
    Node* root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);
    levelOrderTraversal(root);
    cout<<endl;
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    return 0;
}