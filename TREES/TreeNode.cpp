//recurision
//linkedlist
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }

};
  void display(Node* root){
      if(root==NULL) return;
      cout<<root->val<<" ";
      display(root->left);
      display(root->right);
    }

    int sum(Node* root){
        if(root==NULL) return 0;
        int total=root->val;
        total+=sum(root->left);
        total+=sum(root->right);
        return total;
    }

     int size(Node* root){
        if(root==NULL) return 0;
        int total=1;
        total+=size(root->left);
        total+=size(root->right);
        return total;
    }
    int maxIN(Node* root){
        if(root==NULL) return INT_MIN;

        return max(root->val,max(maxIN(root->left),maxIN(root->right))); 
    }
    int prod(Node* root){
        if(root==NULL) return 1;
        int product=root->val;
        product*=prod(root->left)*prod(root->right);
        return product;
    }
    int Levels(Node* root){
        if(root==NULL) return 0;
       int levels=1+max(Levels(root->left),Levels(root->right));
        return levels;

    }
int main(){
    Node* a=new Node(1);//root;
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    
    a->right=b;
    a->left=c;
    b->right=e;
    b->left=d;
    c->left=f;
    c->right=g;
    display(a);

    cout<<sum(a)<<endl;
    cout<<size(a);
    cout<<endl;
    cout<<maxIN(a)<<endl; 
    cout<<prod(a)<<endl;
    cout<<Levels(a)<<endl;



}