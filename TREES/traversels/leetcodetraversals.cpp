
class Solution {
public:
void pre(TreeNode* root,vector<int>& ans){
    if(root==NULL) return;
    pre(root->left,ans);
    pre(root->right,ans);
     ans.push_back(root->val);
}

    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        pre(root,ans);
        return ans;
        
    }
};

class Solution {
public:
void pre(TreeNode* root,vector<int>& ans){
    if(root==NULL) return;
    pre(root->left,ans);
     ans.push_back(root->val);
    pre(root->right,ans);
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        pre(root,ans);
        return ans;
    }
};

class Solution {
public:
void pre(TreeNode* root,vector<int>& ans){
    if(root==NULL) return;
    ans.push_back(root->val);
    pre(root->left,ans);
    pre(root->right,ans);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        pre(root,ans);
        return ans;

    }
};
// just change the order of the recursive calls and the push_back statement to get different traversals.
// In preorder, we visit the root first, then left subtree, and finally right subtree.
// In inorder, we visit the left subtree first, then the root, and finally the right subtree.
// In postorder, we visit the left subtree first, then the right subtree, and finally the root.
