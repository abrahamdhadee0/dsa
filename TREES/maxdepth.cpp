/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int count(TreeNode* root){
    int countl=0;
int countr=0;
    if(root==NULL) return 0;
      countr=  count(root->right);
countl=count(root->left);
    return 1+max(countl,countr);
}
    int maxDepth(TreeNode* root) {
        return count(root);
    }
};