#include <bits/stdc++.h> 
using namespace std;

class node
{
    public:

    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
    public:
    bool operator()(node* a, node* b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue<node*, vector<node*>, compare> minHeap;

    for(int i = 0; i < k; i++)
    {
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    while(minHeap.size() > 0)
    {
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->row;
        int j = temp->col;

        if(j+1 < kArrays[i].size())
        {
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }

    return ans;
}
