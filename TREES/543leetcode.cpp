 
class Solution {
public:
int maxdia =0;
 int Levels(TreeNode* root){
        if(root==NULL) return 0;
       int levels=1+max(Levels(root->left),Levels(root->right));
        return levels;

    }
    int diameterOfBinaryTree(TreeNode* root) {
     if(root==NULL) return 0;
        int dia= Levels(root->left)+Levels(root->right);
        maxdia=max(dia,maxdia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdia;
    }
};
// about diameter of binary tree, we can find the diameter by finding 
//the levels of left and right subtree and adding them together. we can do this//
// for every node and find the maximum diameter.
//interviewer approcach

int levels(Tree *root){
    if(root==NULL) return 0;
   int levels=1+max(levels(root->left),levels(root->right));
    return levels;
}
void helper(Tree *root,int & maxdia){
    if(root==NULL) return;
    int dia= levels(root->left)+levels(root->right);
    maxdia=max(dia,maxdia);
    helper(root->left,maxdia);
    helper(root->right,maxdia);
}
int diameterOfBinaryTree(Tree* root) {
    int maxdia=0;
    helper(root,maxdia);
    return maxdia;
}