#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};
void levelorder(Node* root,int level,int curr){
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
Node* construct(){
    queue<Node*> q;
    Node* root=new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>&i<n){
     Node* temp=q.front();
     q.pop();
     Node* left=new Node(arr[i]);
     Node* right=new Node(arr[j]);
            if(arr[i]!=-1) {
        l=new Node(arr[i]);
            }
            else l=nullptr;
            if(arr[j]!=-1) {
        r=new Node(j!=n && arr[j]);
            }
            else r=nullptr;

            temp->left=l;
            temp->right=r;
            if(l) q.push(l);
            if(r) q.push(r);
        i+=2;
        j+=2;
        return root;
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    Node* root=construct();

}