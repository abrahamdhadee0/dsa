
class Solution {
public:
void helper (TreeNode* root){
    if(root==NULL) return;
    TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    helper(root->left);
    helper(root->right);


}
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
// to invert a binary tree
//, we can swap the left and right child of every node in the tree.
// we can do this by using a helper function that takes a node as input //
//and swaps its left and right child, then recursively calls itself on
// the left and right child of the node. finally, we return the root of the inverted tree.
