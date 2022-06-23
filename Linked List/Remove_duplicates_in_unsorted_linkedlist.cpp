Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(!head || !head->next) return head;
    
    unordered_map<int,bool> visited;
    Node* prev = head;
    Node* curr = head->next;
    visited[prev->data] = true;
    while(curr)
    {
        if(visited[curr->data])
        {
            prev->next = curr->next;
            delete(curr);
        }
        else
        {
            visited[curr->data] = true;
            prev = prev->next;
        }
        curr = prev->next;
    }
    return head;
}