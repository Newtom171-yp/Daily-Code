Node *findMiddle(Node *head) {
    // Write your code here
    int count = 0;
    Node* temp = head;
    Node* temp2 = head;
    while(temp2 && temp2->next)
    {
        temp = temp->next;
        
        temp2 = temp2->next->next;
    }
    return temp;
}