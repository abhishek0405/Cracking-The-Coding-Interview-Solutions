//https://www.codingninjas.com/codestudio/problems/list-of-depths_1229511?topList=cracking-the-coding-interview-questions
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };


    Following is the class structure of the Node class for linked list:

        class Node
        {
        public:
            int data;
            Node *next;
            Node *child;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
                this->child = NULL;
            }
        };

*****************************************************************/



// You need return the head pointer of the linked list
#include<queue>
Node* listOfDepth(TreeNode<int> * root)
{
    // Write your code here.
    queue<TreeNode<int>*> nodesQ;
    Node* node;
    Node* head = NULL;
    nodesQ.push(root);
    
    while(!nodesQ.empty()){
        TreeNode<int>* curr = nodesQ.front();
        nodesQ.pop();
        
        if(head == NULL){
            head = new Node(curr->data);
            node = head;
        }
        else{
            node->next = new Node(curr->data);
            node = node->next;
                                 
        }
        
        if(curr->left){
            nodesQ.push(curr->left);
        }
        if(curr->right){
            nodesQ.push(curr->right);
        }
        
    }
    return head;
}
