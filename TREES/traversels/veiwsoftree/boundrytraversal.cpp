#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};
void boundarytraversal(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    leftboundary(root->left);
    leafnodes(root);
    rightboundary(root->right);
}
void leftboundary(TreeNode* root){
    if(root==NULL) return;
    if(root->left) {
        cout<<root->val<<" ";
        leftboundary(root->left);
    }
    else if(root->right){
        cout<<root->val<<" ";
        leftboundary(root->right);
    }
    void leafnodes(TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            cout<<root->val<<" ";
            return;
        }
        leafnodes(root->left);
        leafnodes(root->right);
    }
    
    void rightboundary(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;    
        rightboundary(root->right);
 if(root->left) rightboundary(root->left);
         cout<<root->val<<" ";
}