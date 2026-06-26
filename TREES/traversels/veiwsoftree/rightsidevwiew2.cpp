class solution{
    public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void preorder(TreeNode* root,vector<int>& ans,int curr){
        if(root==NULL) return;
        ans[level]= root->val;
        preorder(root->left,ans,curr+1);
        preorder(root->right,ans,curr+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preorder(root,ans,0);
        return ans;
    }
};