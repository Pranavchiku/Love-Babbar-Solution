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

Node * inOrderSwap(Node *root){
    if(root->left!=NULL){
        root=root->left;
        while (root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    else{
        root=root->right;
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
}

Node *deleteNode(Node *root, int x) {
    if(root==NULL) return NULL;
    if(x==root->data and root->left==NULL and root->right==NULL){
        free(root);
        return NULL;
    }
    if(x<root->data) root->left=deleteNode(root->left,x);
    else if(x>root->data) root->right=deleteNode(root->right,x);
    else{
        Node *iSwap=inOrderSwap(root);
        root->data=iSwap->data;
        if(root->left!=NULL){
            root->left=deleteNode(root->left,iSwap->data);
        }
        else root->right=deleteNode(root->right,iSwap->data);
    }
    return root;
}

Node* inOrderSuccesor(Node *root,int key){
    Node *suc=NULL;
    while(root!=NULL){
        if(key>=root->data) root=root->right;
        else {
            suc=root;
            root=root->left;
        }
    }
    return suc;
}

Node* inOrderPredecessor(Node *root,int key){
    Node *pre=NULL;
    while(root!=NULL){
        if(key<=root->data) root=root->left;
        else{
            pre=root;
            root=root->right;
        }
    }
    return pre;
}