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

void inOrder(Node *root, vector<int> &v){
    if(root!=NULL){
        inOrder(root->left,v);
        v.push_back(root->data);
        inOrder(root->right,v);
    }
}

Node *insertAtEnd(Node *head, int data){
    Node *p=head;
    while(p->right!=NULL){
        p=p->right;
    }
    Node *n=createNode(data);
    p->right=n;
    n->left=p;
    return head;
}

Node * bToDLL(Node *root)
{
    vector<int> v;
    inOrder(root,v);

    Node *head=createNode(v[0]);

    for(int i=1;i<v.size();i++){
        head=insertAtEnd(head,v[i]);
    }

    return head;

}