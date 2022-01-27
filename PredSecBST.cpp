//https://www.codingninjas.com/codestudio/problems/predecessor-and-successor_920476?topList=cracking-the-coding-interview-questions
/***********************************************************

	Following is the Binary Tree node structure:

	class binaryTreeNode{

	public :
		int data ;
		binaryTreeNode* left ;
		binaryTreeNode* right;

		binaryTreeNode(int data)
		{
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
	};
O(N)

1 3 4 6 7 8 10 13 14
*********************************************************/
void findSuc(binaryTreeNode *root, int key,int &suc,int &ans){
    //base cases
    if(root==NULL){
        return;
    }
    
    if(root->data==key){
        //lefttmost child in right subtree
        if(root->right!=NULL){
            root = root->right;
            while(root->left!=NULL){
                root = root->left;
            }
            ans = root->data;
               
        }
        else{
            ans = suc;
        }
        return;
    }
    
    if(root->data > key){
        suc = root->data;
        findSuc(root->left,key,suc,ans);
    }
    
    if(root->data < key){
        
        findSuc(root->right,key,suc,ans);
    }
   
}
    

void findPrev(binaryTreeNode *root, int key,int &pred,int &ans){
    //base cases
    if(root==NULL){
        return;
    }
    
    if(root->data==key){
        //rightmost child in left subtree
        if(root->left!=NULL){
            root = root->left;
            while(root->right!=NULL){
                root = root->right;
            }
            ans = root->data;
               
        }
        else{
            ans = pred;
        }
        return;
    }
    
    if(root->data > key){
        findPrev(root->left,key,pred,ans);
    }
    
    if(root->data < key){
        pred = root->data;
        findPrev(root->right,key,pred,ans);
    }
   
    
    
}

vector<int> findPreSuc(binaryTreeNode *root, int key)
{
	// Write your code here.
    int pred = -1;
    int suc = -1;
    int ans_prev;
    int ans_next;
    findPrev(root,key,pred,ans_prev);
    findSuc(root,key,suc,ans_next);
    
    return {ans_prev,ans_next};
    
}
