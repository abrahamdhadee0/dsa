#include <bits/stdc++.h>
using namespace std;
int levels(TreeNode* root){
    if(root==NULL) return 0;
    return max(levels(root->left),levels(root->right))+1;
 }
 void print(TreeNode* root,int level,int curr){
    if(root==NULL) return;
    if(curr==level) {
        cout<<root->val<<" ";
        return;}
        
    print(root->left,level,curr+1);
    print(root->right,level,curr+1);
 }
    void printNthLevel(TreeNode* root,int n){
        int h=levels(root);
       for(int i=0;i<h;i++){
           print(root,i,0);
           cout<<endl;
       }
 }