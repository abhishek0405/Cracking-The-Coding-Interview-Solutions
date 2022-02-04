//https://www.codingninjas.com/codestudio/problems/bst-to-sorted-dll_1263694?topList=cracking-the-coding-interview-questions
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

************************************************************/
void inorder(TreeNode<int> *root,TreeNode<int> *&prev,TreeNode<int>* &head){
    //base cases
    if(root == NULL){
        return;
    }
    
    inorder(root->left,prev,head);
    if(prev == NULL){
        head = root;
    }
    else{
        prev->right = root;
        root->left = prev;
    }
    
    prev = root;
    inorder(root->right,prev,head);
}
TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
	// Write your code here.
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int> *prev = NULL;
    TreeNode<int> *head = NULL;
    inorder(root,prev,head);
    return head;
}
