//https://www.codingninjas.com/codestudio/problems/palindrom-linked-list_799352?topList=cracking-the-coding-interview-questions
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
    2->3->5->3->2
    
    1->2->3->4->NULL
    
    1->2->3->2->1
    
    1->2->3->3->2->1
    
*****************************************************************/
LinkedListNode<int>* middle(LinkedListNode<int>*head){
    LinkedListNode<int>* slow;
    LinkedListNode<int>* fast;
    slow = fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

void reverse(LinkedListNode<int> *&head,LinkedListNode<int> *curr,LinkedListNode<int> *prev){
    //base cases
    if(curr==NULL){
        head = prev;
        return;
    }
    reverse(head,curr->next,curr);
    curr->next = prev;
  
    
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int>* mid = middle(head);
    LinkedListNode<int>* head1 = NULL;
    reverse(head1,mid,NULL);
    
    while(head1!=NULL && head!=NULL){
        if(head1->data!=head->data){
            return false;
        }
        head = head->next;
        head1 = head1->next;
    }
    return true;

}
