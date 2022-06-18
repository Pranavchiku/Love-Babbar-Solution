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

void preOrder(Node *root, vector<int> &v, int curr, bool levels[]){
    if(root!=NULL){
        if(!levels[curr]){
            v.push_back(root->data);
            levels[curr]=1;
        }
        preOrder(root->left,v,curr+1,levels);
        preOrder(root->right,v,curr+1,levels);
    }
}
vector<int> leftView(Node *root)
{
   vector<int> v;
   bool levels[101]={0};
   preOrder(root,v,0,levels);
   return v;
}