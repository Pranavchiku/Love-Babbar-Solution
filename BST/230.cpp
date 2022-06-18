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

void inOrder(Node *root, int l, int h, int &c){
    if(root!=NULL){
        inOrder(root->left,l,h,c);
        if(root->data>=l and root->data<=h) c++;
        inOrder(root->right,l,h,c);
    }
}
int getCount(Node *root, int l, int h)
{
    int count=0;
    inOrder(root,l,h,count);
    return count;
}