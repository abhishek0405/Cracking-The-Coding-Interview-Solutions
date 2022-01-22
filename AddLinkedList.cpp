//https://www.codingninjas.com/codestudio/problems/add-two-linked-lists_799487?topList=cracking-the-coding-interview-questions
/************************************************************

    Following is the linked list node structure:
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

3 8 1 2 9
  9 8 2 9 
  
4 7 9 5 8

9 2 1 8 3 5 7
9 2 8 9 
8 5 9 7 4 	  	

1->2->3->4

9 9 
1 1
0 1 1  
  

************************************************************/
void reverse(Node<int>* &head,Node<int>* curr,Node<int>* prev){
    //base case
    if(curr==NULL){
        head = prev;
        return;
    }
    
    reverse(head,curr->next,curr);
    curr->next = prev;
    
}

Node<int>* add(Node<int>* first, Node<int>* second){
    int nodeVal;
    int carry = 0;
    bool head = true;
    Node<int>* firstHead = first;
    Node<int>* curr = first;
    Node<int>* prev = NULL;
    while(first!=NULL || second!=NULL){
        nodeVal = 0;
        if(first!=NULL){
            nodeVal+=first->data;
            first = first->next;
        }
        if(second!=NULL){
            nodeVal+=second->data;
            second = second->next;
        }
        nodeVal+=carry;
        
        if(nodeVal>=10){
            carry = 1;
        }
        else{
            carry = 0;
        }
        
        if(head){
            curr->data = nodeVal%10;
            prev = curr;
            curr = curr->next;
            head = false;
         }
        
        else{
            curr->data = nodeVal%10;
            prev = curr;
            curr = curr->next;
           
        }
        
        
    }
    //11 
    //99
    //check if carry
    if(carry){
         prev->next = new Node<int>(1);
         
    }
    return firstHead;
}
//1->2->3->4

int length(Node<int>* head){
    if(head==NULL){
        return 0;
    }
    return 1 +length(head->next); 
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    // Write your code here
    //reversing both
    reverse(first,first,NULL);
    reverse(second,second,NULL);
    Node<int>* third;
    
    int firstLen = length(first);
    int secondLen = length(second);
    
    if(firstLen>=secondLen){
         third = add(first,second);
    }
    else{
        third = add(second,first);
    }
   
    
    reverse(third,third,NULL);
    return third;
    
    
    
}
