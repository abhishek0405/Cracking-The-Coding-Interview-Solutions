//https://www.codingninjas.com/codestudio/problems/subtree-of-another-tree_893071?topList=cracking-the-coding-interview-questions
/***************************************************
  Following is the TreeNode Structure

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};


   1
  2  3			
 4     5
 
  2
 4 1

4 2 1 3 5

4 2 1

1 2 4 3 5
2 4 1


1 2 3 4 5 6 7 8 9 0 






*****************************************************/
#include<vector>
bool isIdentical(TreeNode<int> *root1,TreeNode<int> * root2){
    //base cases
    if(root1==NULL && root2==NULL){
        return true;
    }
    //as one NULL and another not NULL
    if(root1==NULL || root2==NULL){
        return false;
    }
    
    return root1->val==root2->val 
        && isIdentical(root1->left,root2->left) 
        && isIdentical(root1->right,root2->right);
       
}

void getNodes(TreeNode<int> *root,int key,vector<TreeNode<int>*>&nodes){
    /*
     stores list of nodes with key in the nodes vector
    */
    
    //base case
    if(root==NULL){
        return;
    }
    
    if(root->val==key){
        nodes.push_back(root);
    }
    
    getNodes(root->left,key,nodes);
    getNodes(root->right,key,nodes);
    
    
}

bool isSubtree(TreeNode<int> *T, TreeNode<int> *S)
{
    // Write your code here.
    vector<TreeNode<int>*>nodes;
    int key = S->val;
    getNodes(T,key,nodes);
    
    for(auto &node: nodes){
        if(isIdentical(node,S)){
            return true;
        }
    }
    return false;
    
}
