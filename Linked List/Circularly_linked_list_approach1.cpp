/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    // Write your code here.
    if(!head || head->next == head) return true;
    if(!head->next) return false;
    Node* temp = head;
    
    while(temp)
    {
        temp = temp->next;
        if(temp == head) return true;
    }
    return false;
}
