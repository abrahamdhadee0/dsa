/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int levels(Node* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void preorder(Node* root,vector<int>& ans,int curr){
        if(root==NULL) return;
        ans[curr]= root->data;
        preorder(root->right,ans,curr+1);
        preorder(root->left,ans,curr+1);
        
    }
    vector<int> leftView(Node *root) {
        vector<int> ans(levels(root),0);
        preorder(root,ans,0);
        return ans;
        
    }
};