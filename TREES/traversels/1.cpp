//traversal means to visit all the nodes 
//of a tree in a specific order. //
//There are three common types of tree traversals:
//1. Preorder Traversal: In this traversal,//
// the nodes are visited in the following order:
//1. Visit the root node.
//2. Traverse the left subtree.
//3. Traverse the right subtree.
//2. Inorder Traversal: In this traversal,//
// the nodes are visited in the following order:
//1. Traverse the left subtree.
//2. Visit the root node.
//3. Traverse the right subtree.
//3. Postorder Traversal: In this traversal,//
// the nodes are visited in the following order:
//1. Traverse the left subtree.
//2. Traverse the right subtree.
//3. Visit the root node.
//Here is an example of how to implement these traversals in C++
//                      PREORDER
#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
void preorderTraversal(TreeNode* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(TreeNode* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void postorderTraversal(TreeNode* root){
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Preorder Traversal
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    // Inorder Traversal
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Postorder Traversal
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
