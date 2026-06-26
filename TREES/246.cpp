class Solution {
public:

bool exist(TreeNode* root, TreeNode* target){
    if(root==NULL) return false;
    if(root==target) return true;

    return exist(root->left,target) || exist(root->right,target);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root==NULL) return NULL;

    if(root==p || root==q) return root;

    bool pLeft = exist(root->left,p);
    bool qLeft = exist(root->left,q);

    // p left, q right OR p right, q left
    if(pLeft != qLeft) return root;

    if(pLeft && qLeft)
        return lowestCommonAncestor(root->left,p,q);
    else
        return lowestCommonAncestor(root->right,p,q);
}
};
// to find the lowest common ancestor of two nodes in a binary tree, we can use a recursive approach.
// we can check if the current node is one of the target nodes, if it is, we return the current node.
// if the current node is not one of the target nodes, we can check if the target
// nodes are in the left or right subtree of the current node.
// if they are in different subtrees, then the current node is//
 //the lowest common ancestor. if they are in the same subtree, //
 //we can recursively call the function on that subtree to find the lowest common ancestor.