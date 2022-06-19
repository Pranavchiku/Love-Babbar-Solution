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
//dry run this and BAAM!!
int sum(Node *root){
    root->data=0;
    if(root->left) root->data+=root->left->data+sum(root->left);
    if(root->right) root->data+=root->right->data+sum(root->right);
    return root->data;
}
void toSumTree(Node *root)
{
    sum(root);
}