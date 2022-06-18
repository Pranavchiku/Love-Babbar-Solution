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

void solve(Node *root1, Node *root2, int x, int &count){
    if(root1!=NULL){
        solve(root1->left,root2,x,count);
        Node *temp=search(root2,x-(root1->data));
        if(temp!=NULL) count++;
        solve(root1->right,root2,x,count);
    }
}
int countPairs(Node* root1, Node* root2, int x)
{
    int count=0;
    solve(root1,root2,x,count);
    return count;
}