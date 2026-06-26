#include <bits/stdc++.h>
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
vector<int> preorder(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;
  if(root!=NULL)  st.push(root);
    while(!st.empty()){
        TreeNode* temp=st.top();
        st.pop();
        ans.push_back(temp->val);
            if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
    
    }
    reverse(ans.begin(),ans.end());
    return ans;
}