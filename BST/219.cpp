#include <bits/stdc++.h>
using namespace std;
#define ll long long int


typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int data){
    Node *n=new(Node);
    n->right=n->left=NULL;
    n->data=data;
    return n;
}

void insert(Node *root, int key){

    Node* prev=NULL;
    Node *n=createNode(key);
    while(root!=NULL){
        prev=root;
        if(key==root->data) return;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    if(key>prev->data) prev->right=n;
    else prev->left=n;
    

}

Node *search(Node *root, int key){
    if(root==NULL) return NULL;
    if(key<root->data) return search(root->left,key);
    if(key>root->data) return search(root->right,key);
    if(key==root->data) return root;
}

void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<' ';
        inOrder(root->right);
    }
}



void func(Node *root, Node* &prev, int &f){
    if(root==NULL) return;
    func(root->left,prev,f);
    if(prev!=NULL and root->data<=prev->data){
        f=0;
        return;
    } 
    prev=root;
    func(root->right,prev,f);
}
bool isBST(Node* root) 
{
    int f=1;
    Node *prev=NULL;
    func(root,prev,f);
    return f;
}