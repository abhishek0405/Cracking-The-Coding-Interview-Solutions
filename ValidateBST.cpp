https://www.codingninjas.com/codestudio/problems/validate-bst_799483?topList=cracking-the-coding-interview-questions
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<climits>
bool check(BinaryTreeNode<int> *root,int mini,int maxi){
    //base cases
    if(root==NULL){
        return true;
    }
    bool checkNode = root->data>=mini && root->data<=maxi;
    bool checkLeft = check(root->left,mini,root->data);
    bool checkRight = check(root->right,root->data,maxi);
    
    return checkNode && checkLeft && checkRight;
    
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return check(root,INT_MIN,INT_MAX);
}
