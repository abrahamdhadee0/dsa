void levelorder(TreeNode* root,int level,int curr){
if(root==NULL) return;
if(curr==level) {
    cout<<root->val<<" ";
    return;}
levelorder(root->right,level,curr+1);
levelorder(root->left,level,curr+1);
}