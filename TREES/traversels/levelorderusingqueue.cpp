//BFS
#include<bits/stdc++.h>
using namespace std;

int main(){
    QUEUE<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

}
#include<bits/stdc++.h>
using namespace std;

int main(){
    QUEUE<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
          if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
      
    }

}